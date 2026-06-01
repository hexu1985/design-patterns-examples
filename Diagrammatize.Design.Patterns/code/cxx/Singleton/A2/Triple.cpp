#include "Triple.hpp"
#include <iostream>

Triple Triple::triple[3]{Triple(0), Triple(1), Triple(2)};

Triple::Triple(int id_): id(id_) {
    std::cout << "The instance " << id << " is created." << std::endl;
}

Triple& Triple::getInstance(int id) {
    return triple[id];
}

std::string Triple::toString() const {
    return "[Triple id=" + std::to_string(id) + "]";
}

std::ostream& operator<<(std::ostream& os, const Triple& triple) {
    os << triple.toString();
    return os;
}
