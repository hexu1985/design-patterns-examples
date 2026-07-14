#pragma once

#include <thread>
#include <mutex>
#include <iostream>
#include <string>

#include "Pair.hpp"

class EaterThread {
private:
    std::string name;
    Pair& pair;
    
public:
    // 构造函数：使用引用绑定工具对象
    EaterThread(const std::string& name, Pair& pair)
        : name(name), pair(pair) {}
    
    // 线程执行函数（对应Java的run方法）
    void run() {
        while (true) {
            eat();
        }
    }
    
    // 吃饭方法（对应Java的eat方法）
    void eat() {
        std::unique_lock<std::mutex> lock(pair.getMutex());
        std::cout << name << " takes up " << pair.toString() << " (right)." << std::endl;
        std::cout << name << " is eating now, yum yum!" << std::endl;
        std::cout << name << " puts down " << pair.toString() << " (right)." << std::endl;
    }
    
    // 启动线程的辅助方法
    void start() {
        std::thread t(&EaterThread::run, this);
        t.detach(); // 或者保存线程对象
    }
};
