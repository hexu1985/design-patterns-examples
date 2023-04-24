#include "RandomCountDisplay.hpp"


RandomCountDisplay::RandomCountDisplay(DisplayImpl* impl): CountDisplay(impl) {
}

void RandomCountDisplay::randomDisplay(int times) {
    multiDisplay(random.random(times));
}
