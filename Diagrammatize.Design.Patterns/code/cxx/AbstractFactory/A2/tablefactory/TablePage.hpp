#pragma once

#include "factory/Page.hpp"

class TablePage: public Page {
public:
    TablePage(const std::string& title, const std::string& author); 

    std::string makeHTML() override;
};
