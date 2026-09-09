#pragma once

#include <thread>
#include <random>
#include <chrono>
#include <string>
#include <memory>
#include <iostream>

#include "Data.hpp"

class SaverThread {
private:
    Data& data;
    std::string threadName;
    std::thread thread;
    
public:
    SaverThread(const std::string& name, Data& data) : data(data), threadName(name) {
    }

    ~SaverThread() {
        join();
    }

    void run() {
        current_thread::set_thread_name(threadName);
        try {
            while (true) {
                data.save();
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        } catch (const std::exception& e) {
            std::cerr << "SaverThread Exception: " << e.what() << std::endl;
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
