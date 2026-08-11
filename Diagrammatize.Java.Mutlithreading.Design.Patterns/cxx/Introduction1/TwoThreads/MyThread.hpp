#pragma once

#include <iostream>
#include <thread>

class MyThread {
public:
    void run() {
        for (int i = 0; i < 10000; i++) {
            std::cout << "Nice!";
        }
    }

    void start() {
        t = std::thread(&MyThread::run, this);
    }

    void join() {
        if (t.joinable()) {
            t.join();
        }
    }

private:
    std::thread t;
};
