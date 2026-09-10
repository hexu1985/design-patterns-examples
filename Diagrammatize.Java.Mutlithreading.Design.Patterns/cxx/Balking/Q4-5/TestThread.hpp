#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <stdexcept>

class TestThread {
public:
    void start() {
        if (started_) {
            throw std::logic_error("IllegalThreadStateException");
        }
        started_ = true;
        thread_ = std::thread([this] { run(); });
    }

    void join() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }

private:
    void run() {
        std::cout << "BEGIN" << std::flush;
        for (int i = 0; i < 50; i++) {
            std::cout << "." << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        std::cout << "END" << std::endl;
    }

    bool started_ = false;
    std::thread thread_;
};
