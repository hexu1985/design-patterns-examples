#include "Trouble.hpp"
#include <iostream>

Trouble::Trouble(int number_): number(number_) {
}

int Trouble::getNumber() const {
    return number;
}

std::string Trouble::toString() const {
    return "[Trouble " + std::to_string(number) + "]";
}

std::ostream& operator<<(std::ostream& os, const Trouble& t) {
    os << t.toString();
    return os;
}
