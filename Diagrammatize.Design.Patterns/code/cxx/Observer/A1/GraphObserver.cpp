#include "GraphObserver.hpp"
#include "NumberGenerator.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void GraphObserver::update(NumberGenerator* generator) {
    std::cout << "GraphObserver:";
    int count = generator->getNumber();
    for (int i = 0; i < count; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
