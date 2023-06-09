#pragma once

#include "Display.hpp"

class StringDisplay: public Display {
private:
    std::string string;                          // 要显示的字符串

public:
    StringDisplay(const std::string& string);           // 通过参数传入要显示的字符串
    int getColumns() override;                       // 字符数
    int getRows() override;                          // 行数是1
    std::string getRowText(int row) override;             // 仅当row为0时返回值
};
