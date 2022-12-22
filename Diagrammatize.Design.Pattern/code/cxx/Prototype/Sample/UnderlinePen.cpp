#include "UnderlinePen.hpp"
#include <iostream>

UnderlinePen::UnderlinePen(char ulchar_) : ulchar(ulchar_) {}

UnderlinePen::~UnderlinePen() {}

void UnderlinePen::use(const std::string& s) {
    int length = s.length();
    std::cout << "\""  << s << "\"" << '\n';
    std::cout << " ";
    for (int i = 0; i < length; i++) {
        std::cout << ulchar;
    }
    std::cout << '\n';
}

UnderlinePen* UnderlinePen::createClone() {
    return new UnderlinePen(*this);
}
