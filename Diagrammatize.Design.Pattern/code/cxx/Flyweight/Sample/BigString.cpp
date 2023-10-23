#include "BigString.hpp"
#include "BigCharFactory.hpp"

BigString::BigString(const std::string& string) {
    bigchars.resize(string.length());
    auto& factory = BigCharFactory::getInstance();
    for (int i = 0; i < bigchars.size(); i++) {
        bigchars[i] = factory.getBigChar(string[i]);
    }
}

void BigString::print() {
    for (int i = 0; i < bigchars.size(); i++) {
        bigchars[i]->print();
    }
}
