#pragma once

#include "factory/Link.hpp"

class TableLink: public Link {
public:
    TableLink(const std::string& caption, const std::string& url);

    std::string makeHTML() override;
};
