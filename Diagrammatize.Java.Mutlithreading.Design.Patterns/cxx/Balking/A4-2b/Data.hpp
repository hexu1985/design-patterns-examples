#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <chrono>
#include <thread>
#include "thread_name.hpp"

class Data {
private:
    const std::string filename;  // 保存的文件名称
    std::string content;         // 数据内容
    bool changed;                // 修改后的内容若未保存，则为true
    std::mutex mtx;              // 互斥锁，用于线程安全

    // 将数据内容实际保存到文件中
    void doSave() {
        std::cout << current_thread::get_thread_name() << " calls doSave, content = " << content << std::endl;
        std::ofstream writer(filename);
        writer << content;
        writer.close();
    }

public:
    Data(const std::string& filename, const std::string& content) 
        : filename(filename), content(content), changed(true) {}

    // 修改数据内容
    void change(const std::string& newContent) {
        std::lock_guard<std::mutex> lock(mtx);
        content = newContent;
        changed = true;
    }

    // 若数据内容修改过，则保存到文件中
    void save() {
        if (!changed) {
            std::cout << current_thread::get_thread_name() << " balks" << std::endl;
            return;
        }
        doSave();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        changed = false;
    }
};
