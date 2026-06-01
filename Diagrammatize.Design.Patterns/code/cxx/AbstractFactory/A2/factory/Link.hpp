#pragma once

#include "Item.hpp"

class Link: public Item {
protected:
    std::string url;

public:
    Link(const std::string& caption, const std::string& url);
};
