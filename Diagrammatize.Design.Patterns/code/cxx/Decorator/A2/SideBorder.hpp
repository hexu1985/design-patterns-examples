#pragma once

#include "Border.hpp"

class SideBorder: public Border {
private:
    char borderChar;                        // 表示装饰边框的字符

public:
    SideBorder(Display* display, char ch);   // 通过构造函数指定Display和装饰边框字符 
    int getColumns() override;                       // 字符数为字符串字符数加上两侧边框字符数 
    int getRows() override;                          // 行数即被装饰物的行数
    std::string getRowText(int row) override;             // 指定的那一行的字符串为被装饰物的字符串加上两侧的边框的字符 
};
