#pragma once

#include <vector>
#include "BigChar.hpp"

class BigString {
private:
    std::vector<BigChar*> bigchars;

public:
    BigString(const std::string& string, bool shared);

    void initShared(const std::string& string);
    void initUnshared(const std::string& string);

    void print();
};
