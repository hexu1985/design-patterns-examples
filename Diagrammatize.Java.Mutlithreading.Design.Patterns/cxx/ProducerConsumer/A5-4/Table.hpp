#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <thread>

#include "thread_name.hpp"

class Table {
public:
    explicit Table(int count)
        : buffer_(count), tail_(0), head_(0), count_(0) {}

    // 放置蛋糕
    void put(const std::string& cake) {
        std::unique_lock<std::mutex> lock(mutex_);
        std::cout << current_thread::get_thread_name() << " puts " << cake << std::endl;

        while (count_ >= static_cast<int>(buffer_.size())) {
            not_empty_or_full_.wait(lock);
        }

        buffer_[tail_] = cake;
        tail_ = (tail_ + 1) % buffer_.size();
        count_++;
        not_empty_or_full_.notify_all();
    }

    // 取蛋糕
    std::string take() {
        std::unique_lock<std::mutex> lock(mutex_);

        while (count_ <= 0) {
            not_empty_or_full_.wait(lock);
        }

        std::string cake = buffer_[head_];
        head_ = (head_ + 1) % buffer_.size();
        count_--;
        not_empty_or_full_.notify_all();

        std::cout << current_thread::get_thread_name() << " takes " << cake << std::endl;
        return cake;
    }

private:
    std::vector<std::string> buffer_;
    int tail_;   // 下次 put 的位置
    int head_;   // 下次 take 的位置
    int count_;  // buffer 中的蛋糕个数

    std::mutex mutex_;
    std::condition_variable not_empty_or_full_;
};
