#pragma once

#include <string>

#include "DisplayImpl.hpp"

class StringDisplayImpl: public DisplayImpl {
private:
    std::string string;     // 要显示的字符串
    int width;              // 以字节单位计算出的字符串的宽度

public:
    StringDisplayImpl(const std::string& string);

    void rawOpen() override;
    void rawPrint() override;
    void rawClose() override;

private:
    void printLine();
};
