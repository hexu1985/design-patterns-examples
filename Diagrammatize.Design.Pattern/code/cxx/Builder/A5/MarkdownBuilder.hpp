#pragma once

#include "Builder.hpp"
#include <fstream>

class MarkdownBuilder : public Builder {
private:
    std::string filename;                                                     // 文件名
    std::ofstream writer;                                                     // 用于编写文件的ofstream

public:
    ~MarkdownBuilder() override;

    void makeTitle(const std::string& title) override;
    void makeString(const std::string& str) override;
    void makeItems(const std::vector<std::string>& items) override;
    void close() override;

    std::string getResult();
};


