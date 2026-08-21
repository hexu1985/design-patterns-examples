#pragma once

#include <atomic>
#include <thread>
#include <iostream>

#include "CopyOnWriteArrayList.hpp"

class ReaderThread {
private:
    CopyOnWriteArrayList& list;
    std::thread thread;
    std::atomic<bool> running{true};

public:
    ReaderThread(CopyOnWriteArrayList& list) : list(list) {}

    ~ReaderThread() {
        running = false;
        if (thread.joinable()) {
            thread.join();
        }
    }

    void run() {
        while (true) {
            auto snapshot = list.getSnapshot();
            for (int n : *snapshot) {
                std::cout << n << std::endl;
            }
        }
    }

    void start() {
        thread = std::thread(&ReaderThread::run, this);
    }
};
