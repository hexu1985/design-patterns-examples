#include "CountDisplay.hpp"

CountDisplay::CountDisplay(DisplayImpl* impl): Display(impl) {
}

void CountDisplay::multiDisplay(int times) {
    open();
    for (int i = 0; i < times; i++) {
        print();
    }
    close();
}

