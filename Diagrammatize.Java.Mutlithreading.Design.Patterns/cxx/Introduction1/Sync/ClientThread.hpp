#include "Bank.hpp"

#include <thread>
#include <chrono>
#include <iostream>  // 可选，用于调试

class ClientThread {
private:
    Bank& bank;   // 使用引用，避免拷贝

public:
    // 构造函数，绑定一个 Bank 对象的引用
    ClientThread(Bank& bank) : bank(bank) {}

    // 线程执行的函数，对应 Java 的 run()
    void run() {
        while (true) {
            bool ok = bank.withdraw(1000);
            if (ok) {
                bank.deposit(1000);
            }
            // 可选：添加短暂延迟以降低 CPU 占用，类似 Java 的 Thread.sleep()
            // std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void start() {
        std::thread thr(&ClientThread::run, this);
        thr.detach();
    }
};
