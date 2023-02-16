#include "IDCard.hpp"
#include <iostream>

IDCard::IDCard(const std::string& owner_, int serial_): owner(owner_), serial(serial_) {
    std::cout << "制作" << owner << "(" << serial << ")" << "的ID卡。" << std::endl;
}

void IDCard::use() {
    std::cout << "使用" << owner << "(" << serial << ")" << "的ID卡。" << std::endl;
}

std::string IDCard::getOwner() {
    return owner;
}

int IDCard::getSerial() {
    return serial;
}
