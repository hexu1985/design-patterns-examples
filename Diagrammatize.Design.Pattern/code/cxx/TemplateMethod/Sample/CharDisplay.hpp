#pragma once

#include "AbstractDisplay.hpp"

class CharDisplay : public AbstractDisplay {  // CharDisplay是AbstractDisplay的子类 
private:
    char ch;                                // 需要显示的字符

public:
    CharDisplay(char ch_):ch(ch_) {                 // 构造函数中接收的字符被
    }                                               // 保存在字段中

    void open() override; 
    void print() override;
    void close() override; 
};
