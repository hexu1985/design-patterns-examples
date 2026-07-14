#pragma once

#include <thread>
#include <mutex>
#include <iostream>
#include <string>

#include "Tool.hpp"

class EaterThread {
private:
    std::string name;
    Tool& lefthand;
    Tool& righthand;
    
public:
    // 构造函数：使用引用绑定工具对象
    EaterThread(const std::string& name, Tool& lefthand, Tool& righthand)
        : name(name), lefthand(lefthand), righthand(righthand) {}
    
    // 线程执行函数（对应Java的run方法）
    void run() {
        while (true) {
            eat();
        }
    }
    
    // 吃饭方法（对应Java的eat方法）
    void eat() {
        // 使用 std::unique_lock 或 std::lock_guard 实现 synchronized
        std::unique_lock<std::mutex> lock1(lefthand.getMutex());
        std::cout << name << " takes up " << lefthand.toString() << " (left)." << std::endl;
        
        std::unique_lock<std::mutex> lock2(righthand.getMutex());
        std::cout << name << " takes up " << righthand.toString() << " (right)." << std::endl;
        std::cout << name << " is eating now, yum yum!" << std::endl;
        std::cout << name << " puts down " << righthand.toString() << " (right)." << std::endl;
        // lock2 自动解锁
        std::cout << name << " puts down " << lefthand.toString() << " (left)." << std::endl;
        // lock1 自动解锁
    }
    
    // 启动线程的辅助方法
    void start() {
        std::thread t(&EaterThread::run, this);
        t.detach(); // 或者保存线程对象
    }
};
