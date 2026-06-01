#include "Singleton.hpp"
#include <iostream>
#include <thread>
#include <chrono>

Singleton* Singleton::singleton = nullptr;

Singleton::Singleton() {
    std::cout << "生成了一个实例。" << std::endl;
    slowdown();                             
}

void Singleton::slowdown() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

Singleton& Singleton::getInstance() {
    if (singleton == nullptr) {
        singleton = new Singleton();
    }
    return *singleton;
}
