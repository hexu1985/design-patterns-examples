#pragma once

#include "Builder.hpp"

class TextBuilder : public Builder {
private:
    std::string buffer;      // 文档内容保存在该字段中

public:
    ~TextBuilder() override;

    void makeTitle(const std::string& title) override;
    void makeString(const std::string& str) override;
    void makeItems(const std::vector<std::string>& items) override;
    void close() override;

    std::string getResult();
};
