#pragma once

#include <thread>
#include <iostream>
#include <string>
#include <chrono>

class PrintPersonThread {
private:
    const Person& person;  // 或使用 std::shared_ptr<Person>

public:
    // 构造函数
    PrintPersonThread(const Person& p) : person(p) {}

    // 线程执行函数
    void run() {
        while (true) {
            std::cout << std::this_thread::get_id() << " prints " 
                      << person.toString() << std::endl;
        }
    }

    // 启动线程的便捷方法
    void start() {
        std::thread t(&PrintPersonThread::run, this);
        t.detach();  // 分离线程，类似Java的Thread.start()
    }
};
