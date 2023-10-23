#pragma once

#include <vector>
#include "BigChar.hpp"

class BigString {
private:
    std::vector<BigChar*> bigchars;

public:
    BigString(const std::string& string);

    void print();
};
