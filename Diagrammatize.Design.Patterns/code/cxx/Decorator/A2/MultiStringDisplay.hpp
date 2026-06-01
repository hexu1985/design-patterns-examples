#pragma once

#include "Display.hpp"
#include <vector>

class MultiStringDisplay: public Display {
private:
    std::vector<std::string> body;       // 要显示的字符串
    int columns = 0;                        // 最大字符数

public:
    void add(const std::string& msg);                   // 添加字符串

    int getColumns() override;                       // 获取字符数
    int getRows() override;                          // 获取行数
    std::string getRowText(int row) override;             // 获取指定行的内容

private:
    void updateColumn(const std::string& msg);         // 更新字符数
    std::string spaces(int count);               // 补上空格
};
