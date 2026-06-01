#pragma once

#include "Context.hpp"
#include "Executor.hpp"

class Node: public Executor {
public:
    virtual ~Node();
    virtual void parse(Context& context) = 0;
    virtual std::string toString() = 0;
};
