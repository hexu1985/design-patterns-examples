#include "IncreaseDisplay.hpp"

IncreaseDisplay::IncreaseDisplay(DisplayImpl* impl, int step_): CountDisplay(impl), step(step_) {
}

void IncreaseDisplay::increaseDisplay(int level) {
    int count = 0;
    for (int i = 0; i < level; i++) {
        multiDisplay(count);
        count += step;
    }
}

