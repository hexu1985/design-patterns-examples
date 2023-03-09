#pragma once

#include "factory/Link.hpp"

class ListLink: public Link {
public:
    ListLink(const std::string& caption, const std::string& url);

    std::string makeHTML() override;
};
