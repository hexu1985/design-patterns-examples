#pragma once

#include <thread>
#include <random>
#include <chrono>
#include <string>
#include <memory>
#include <iostream>

#include "Data.hpp"
#include "thread_name.hpp"

class ChangerThread {
private:
    Data& data;
    std::string threadName;
    std::thread thread;
    std::mt19937 random;  // 随机数生成器
    std::uniform_int_distribution<int> dist;
    
public:
    ChangerThread(const std::string& name, Data& data) 
        : data(data), threadName(name), random(std::random_device{}()), dist(0, 999) {}

    ~ChangerThread() {
        join();
    }
    
    void run() {
        current_thread::set_thread_name(threadName);
        try {
            for (int i = 0; true; i++) {
                data.change("No." + std::to_string(i));  // 修改数据
                std::this_thread::sleep_for(
                    std::chrono::milliseconds(dist(random))
                );  // 执行其他操作
                data.save();  // 显式地保存
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    
    void start() {
        thread = std::thread([this]() { this->run(); });
    }

    void join() {
        if (thread.joinable()) {
            thread.join();
        }
    }    
};
