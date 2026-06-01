#pragma once

#include "Border.hpp"

class FullBorder: public Border {
public: 
    FullBorder(Display* display); 

    int getColumns() override;                   // 字符数为被装饰物的字符数加上两侧边框字符数
    int getRows() override;                      // 行数为被装饰物的行数加上上下边框的行数
    std::string getRowText(int row) override;         // 指定的那一行的字符串
private: 
    std::string makeLine(char ch, int count);         // 生成一个重复count次字符ch的字符串 
};
