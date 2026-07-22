#pragma once

#include <iostream>
#include <thread>
#include <string>
#include <utility>

class PrintThread {
public:
    explicit PrintThread(const std::string& msg) : message(msg) {}

    void start() {
        thread_ = std::thread(&PrintThread::run, this);
    }

    void join() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }

private:
    void run() {
        for (int i = 0; i < 10000; ++i) {
            std::cout << message;
        }
    }

    std::string message;
    std::thread thread_;
};

