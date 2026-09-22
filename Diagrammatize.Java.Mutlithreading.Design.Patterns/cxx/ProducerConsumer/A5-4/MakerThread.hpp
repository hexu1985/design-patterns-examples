#pragma once

#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
#include <iostream>

#include "Table.hpp"
#include "thread_name.hpp"

class MakerThread {
public:
    MakerThread(const std::string& name, Table& table, long seed)
        : name_(name), table_(table), random_(seed) {}

    ~MakerThread() {
        join();
    }

    void start() {
        thread_ = std::thread(&MakerThread::run, this);
    }

    void join() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }

    void run() {
        current_thread::set_thread_name(name_);
        try {
            std::uniform_int_distribution<int> dist(0, 999);
            while (true) {
                // Java: Thread.sleep(random.nextInt(1000));
                std::this_thread::sleep_for(
                    std::chrono::milliseconds(dist(random_)));

                std::string cake =
                    "[ Cake No." + std::to_string(nextId()) +
                    " by " + name_ + " ]";
                table_.put(cake);
            }
        } catch (...) {
            // 对应 Java 的 InterruptedException 处理（此处为空）
        }
    }

private:
    // 对应 Java 的 private static synchronized int nextId()
    static int nextId() {
        std::lock_guard<std::mutex> lock(id_mutex_);
        return id_++;
    }

    std::string name_;
    Table& table_;
    std::mt19937 random_;
    std::thread thread_;

    static int id_;                 // 蛋糕的流水号（所有糕点师共用）
    static std::mutex id_mutex_;    // 保护 id_ 的锁
};
