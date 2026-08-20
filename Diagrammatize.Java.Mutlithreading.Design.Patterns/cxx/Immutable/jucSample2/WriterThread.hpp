#pragma once

#include <atomic>
#include <thread>
#include <vector>

class WriterThread {
private:
    std::vector<int>& list;  // 使用引用，允许修改
    std::thread thread;
    std::atomic<bool> running{true};
    
public:
    WriterThread(std::vector<int>& list): list(list) {}
    
    ~WriterThread() {
        running = false;
        if (thread.joinable()) {
            thread.join();
        }
    }

    void run() {
        for (int i = 0; true; i++) {
            list.push_back(i);
            list.erase(list.begin());  // 移除第一个元素
        }
    }

    void start() {
        thread = std::thread(&WriterThread::run, this);
    }
};
