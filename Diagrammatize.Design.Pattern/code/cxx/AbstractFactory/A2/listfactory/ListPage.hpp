#pragma once

#include "factory/Page.hpp"

class ListPage: public Page {
public:
    ListPage(const std::string& title, const std::string& author); 

    std::string makeHTML() override;
};
