#pragma once

#include "Context.hpp"

class Node {
public:
    virtual ~Node();
    virtual void parse(Context& context) = 0;
    virtual std::string toString() = 0;
};
