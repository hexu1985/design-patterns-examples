#include "RandomCountDisplay.hpp"
#include <chrono>

RandomCountDisplay::RandomCountDisplay(DisplayImpl* impl): 
    CountDisplay(impl), 
    random(std::chrono::system_clock::now().time_since_epoch().count()) {
}

void RandomCountDisplay::randomDisplay(int times) {
    multiDisplay(random.randomInt(0, times-1));
}
