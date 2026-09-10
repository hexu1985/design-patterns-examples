#pragma once

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <thread>

#include "TimeoutException.hpp"

class Host {
public:
    explicit Host(long timeout_ms)
        : timeout_(timeout_ms), ready_(false) {}

    // 修改状态
    void setExecutable(bool on) {
        std::lock_guard<std::mutex> lock(mutex_);
        ready_ = on;
        cv_.notify_all();
    }

    // 检查状态之后再执行
    void execute() {
        auto start = std::chrono::steady_clock::now();

        std::unique_lock<std::mutex> lock(mutex_);
        while (!ready_) {
            auto now = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
            long rest = timeout_ - elapsed;   // 剩余的等待时间

            if (rest <= 0) {
                throw TimeoutException(
                    "now - start = " + std::to_string(elapsed) +
                    ", timeout = " + std::to_string(timeout_));
            }

            // 等待最多 rest 毫秒，或直到被 notify
            cv_.wait_for(lock, std::chrono::milliseconds(rest));
        }

        doExecute();
    }

private:
    void doExecute() {
        std::cout << std::this_thread::get_id() << " calls doExecute" << std::endl;
    }

    long timeout_;
    bool ready_;
    std::mutex mutex_;
    std::condition_variable cv_;
};

