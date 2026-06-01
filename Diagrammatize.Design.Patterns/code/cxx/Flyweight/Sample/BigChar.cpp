#include "BigChar.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

BigChar::BigChar(char charname_): charname(charname_) {
    std::ifstream reader(std::string("big") + charname+ ".txt");
    if (!reader) {
        fontdata = charname + std::string("?");
        return;
    }

    std::string line;
    std::stringstream buf;
    while (std::getline(reader, line)) {
        buf << line << "\n";
    }
    reader.close();
    fontdata = buf.str();
}

void BigChar::print() {
    std::cout << fontdata;
}
