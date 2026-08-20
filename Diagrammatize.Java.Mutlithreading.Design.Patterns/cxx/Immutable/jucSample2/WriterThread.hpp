#pragma once

#include <atomic>
#include <thread>
#include <vector>

class WriterThread {
private:
    std::vector<int>& list;  // 使用引用，允许修改
    std::mutex& mutex;
    std::thread thread;
    std::atomic<bool> running{true};
    
public:
    WriterThread(std::vector<int>& list, std::mutex& mutex): list(list), mutex(mutex) {}
    
    ~WriterThread() {
        running = false;
        if (thread.joinable()) {
            thread.join();
        }
    }

    void run() {
        for (int i = 0; true; i++) {
            std::lock_guard<std::mutex> lock(mutex);
            list.push_back(i);
            list.erase(list.begin());  // 移除第一个元素
        }
    }

    void start() {
        thread = std::thread(&WriterThread::run, this);
    }
};
