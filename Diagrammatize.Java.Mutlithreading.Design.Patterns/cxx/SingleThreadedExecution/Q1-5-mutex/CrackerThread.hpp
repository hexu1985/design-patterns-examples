#pragma once

#include <thread>
#include <memory>

class CrackerThread {
private:
    SecurityGate* gate=nullptr;  // 使用引用，对应Java的final引用
    std::thread thr;

public:
    // 构造函数：使用引用初始化
    CrackerThread(SecurityGate& gate_) : gate(&gate_) {}

    void start() {
        thr = std::thread(&CrackerThread::run, this);
    }

    void run() {
        for (int i = 0; i < 10; ++i) {
            gate->enter();
            gate->exit();
        }
    }

    void join() {
        thr.join();
    }
};

