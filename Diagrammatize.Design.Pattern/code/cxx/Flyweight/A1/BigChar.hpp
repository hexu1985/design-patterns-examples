#pragma once

#include <string>

class BigChar {
private:
    char charname;
    std::string fontdata;

public:
    BigChar(char charname);

    void print();
};
