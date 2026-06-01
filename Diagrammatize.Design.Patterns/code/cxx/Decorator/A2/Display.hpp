#pragma once

#include <string>

class Display {
public:
    virtual ~Display();
    virtual int getColumns() = 0;               // 获取横向字符数
    virtual int getRows() = 0;                  // 获取纵向行数
    virtual std::string getRowText(int row) = 0;     // 获取第row行的字符串
    void show();                            // 全部显示
};
