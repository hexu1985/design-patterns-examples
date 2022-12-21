#pragma once

#include "Builder.hpp"
#include <fstream>

class HTMLBuilder : public Builder {
private:
    std::string filename;                                                     // 文件名
    std::ofstream writer;                                                     // 用于编写文件的ofstream

public:
    ~HTMLBuilder() override;

    void buildTitle(const std::string& title) override;
    void buildString(const std::string& str) override;
    void buildItems(const std::vector<std::string>& items) override;
    void buildDone() override;

    std::string getResult();
};

