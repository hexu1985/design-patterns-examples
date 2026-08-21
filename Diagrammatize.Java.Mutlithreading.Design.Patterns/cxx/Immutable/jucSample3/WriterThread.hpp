#pragma once

#include <atomic>
#include <thread>

#include "CopyOnWriteArrayList.hpp"

class WriterThread {
private:
    CopyOnWriteArrayList& list;
    std::thread thread;
    std::atomic<bool> running{true};
    
public:
    WriterThread(CopyOnWriteArrayList& list): list(list) {}
    
    ~WriterThread() {
        running = false;
        if (thread.joinable()) {
            thread.join();
        }
    }

    void run() {
        for (int i = 0; true; i++) {
            list.add(i);
            list.remove(0);  // 移除第一个元素
        }
    }

    void start() {
        thread = std::thread(&WriterThread::run, this);
    }
};
