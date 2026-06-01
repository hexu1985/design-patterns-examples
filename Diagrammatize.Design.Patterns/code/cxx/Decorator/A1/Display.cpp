#include "Display.hpp"
#include <iostream>

Display::~Display() {
}

void Display::show() {
    for (int i = 0; i < getRows(); i++) {
        std::cout << getRowText(i) << std::endl;
    }
}
