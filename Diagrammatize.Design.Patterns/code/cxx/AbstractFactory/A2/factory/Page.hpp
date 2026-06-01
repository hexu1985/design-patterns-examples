#pragma once

#include "Item.hpp"
#include <vector>

class Page {
protected:
    std::string title;
    std::string author;
    std::vector<Item*> content;

public:
    Page(const std::string& title, const std::string& author); 

    void add(Item* item);

    void output();

    virtual std::string makeHTML() = 0;
};
