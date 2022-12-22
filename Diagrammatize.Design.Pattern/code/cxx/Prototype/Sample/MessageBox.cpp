#include "MessageBox.hpp"
#include <iostream>

MessageBox::MessageBox(char decochar_) : decochar(decochar_) {}

MessageBox::~MessageBox() {}

void MessageBox::use(const std::string& s) {
    int length = s.length();
    for (int i = 0; i < length + 4; i++) {
        std::cout << decochar; 
    }
    std::cout << '\n';
    std::cout << decochar << " "  << s << " " << decochar << '\n';
    for (int i = 0; i < length + 4; i++) {
        std::cout << decochar;
    }
    std::cout << '\n';
}

MessageBox* MessageBox::createClone() {
    return new MessageBox(*this);
}
