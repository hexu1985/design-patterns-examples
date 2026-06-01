#pragma once

#include "Builder.hpp"
#include <sstream>

class TextBuilder : public Builder {
private:
    std::ostringstream buffer;      // 文档内容保存在该字段中

public:
    ~TextBuilder() override;

    void buildTitle(const std::string& title) override;
    void buildString(const std::string& str) override;
    void buildItems(const std::vector<std::string>& items) override;
    void buildDone() override;

    std::string getResult();
};
