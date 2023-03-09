#pragma once

#include <string>

class Item {
protected:
    std::string caption;

public:
    Item(const std::string& caption);

    virtual ~Item();
    virtual std::string makeHTML() = 0;
};

