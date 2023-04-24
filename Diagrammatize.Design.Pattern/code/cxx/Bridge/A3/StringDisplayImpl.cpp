#include "StringDisplayImpl.hpp"
#include <iostream>

StringDisplayImpl::StringDisplayImpl(const std::string& string_):
    string(string_), width(string_.size()) {
}

void StringDisplayImpl::rawOpen()  {
    printLine();
}

void StringDisplayImpl::rawPrint() {
    std::cout << "|" << string << "|" << std::endl;
}

void StringDisplayImpl::rawClose() {
    printLine();
}

void StringDisplayImpl::printLine() {
    std::cout << "+";                          // 显示用来表示方框的角的"+"
    for (int i = 0; i < width; i++) {          // 显示width个"-"
        std::cout << "-";                      // 将其用作方框的边框
    }
    std::cout << "+" << std::endl;             // 显示用来表示方框的角的"+"
}
