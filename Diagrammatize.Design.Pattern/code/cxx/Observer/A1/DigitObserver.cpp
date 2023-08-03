#include "DigitObserver.hpp"
#include "NumberGenerator.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void DigitObserver::update(NumberGenerator* generator) {
    std::cout << "DigitObserver:" << generator->getNumber() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
