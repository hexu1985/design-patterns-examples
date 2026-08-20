#pragma once

#include <atomic>
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

class ReaderThread {
private:
    const std::vector<int>& list;  // 使用引用保持与Java中final类似的效果
    std::mutex& mutex;
    std::thread thread;
    std::atomic<bool> running{true};

public:
    ReaderThread(const std::vector<int>& list, std::mutex& mutex) : list(list), mutex(mutex) {}

    ~ReaderThread() {
        running = false;
        if (thread.joinable()) {
            thread.join();
        }
    }

    void run() {
        while (true) {
            std::lock_guard<std::mutex> lock(mutex);
            for (int n : list) {
                std::cout << n << std::endl;
            }
        }
    }

    void start() {
        thread = std::thread(&ReaderThread::run, this);
    }
};
