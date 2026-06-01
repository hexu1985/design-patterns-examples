#include "Banner.hpp"

#include <iostream>

Banner::Banner(const std::string& string_): string(string_) {
}

void Banner::showWithParen() {
    std::cout << "(" << string << ")" << std::endl;
}

void Banner::showWithAster() {
    std::cout << "*" << string << "*" << std::endl;
}
