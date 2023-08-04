#include "RandomNumberGenerator.hpp"
#include <thread>
#include <chrono>

int RandomNumberGenerator::getNumber() {
    return number;
}

void RandomNumberGenerator::execute() {
    for (int i = 0; i < 20; i++) {
        number = random.randomInt(0, 49);
        notifyObservers();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
