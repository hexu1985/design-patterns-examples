#pragma once

#include <atomic>
#include <thread>
#include <vector>
#include <iostream>

class ReaderThread {
private:
    const std::vector<int>& list;  // 使用引用保持与Java中final类似的效果
    std::thread thread;
    std::atomic<bool> running{true};

public:
    ReaderThread(const std::vector<int>& list) : list(list) {}

    ~ReaderThread() {
        running = false;
        if (thread.joinable()) {
            thread.join();
        }
    }

    void run() {
        while (true) {
            for (int n : list) {
                std::cout << n << std::endl;
            }
        }
    }

    void start() {
        thread = std::thread(&ReaderThread::run, this);
    }
};
