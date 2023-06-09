#pragma once

#include "Border.hpp"

class UpDownBorder: public Border {
private:
    char borderChar;                         // 表示装饰边框的字符 

public:
    UpDownBorder(Display* display, char ch);  // 通过构造函数指定Display和装饰边框字符
    int getColumns() override;                        // 列数与要显示的内容的字符数相同 
    int getRows() override;                           // 行数是内容的行数加上上下边框
    std::string getRowText(int row) override;              // 获取指定行的内容
    
private:
    std::string makeLine(char ch, int count);    // 生成一个由count个字符ch连续组成的字符串 
};

