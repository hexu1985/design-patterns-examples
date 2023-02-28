#include "Singleton.hpp"
#include <iostream>

Singleton Singleton::singleton{};

Singleton::Singleton() {
    std::cout << "生成了一个实例。" << std::endl;
}

Singleton& Singleton::getInstance() {
    return singleton;
}


