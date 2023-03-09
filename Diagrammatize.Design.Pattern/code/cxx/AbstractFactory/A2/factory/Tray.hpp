#pragma once

#include "Item.hpp"
#include <vector>

class Tray: public Item {
protected:
    std::vector<Item*> tray;

public:
    Tray(const std::string& caption);

    void add(Item* item);
};
