#pragma once

#include <string>

#include "Node.hpp"
#include "Context.hpp"

// <primitive command> ::= go | right | left
class PrimitiveCommandNode: public Node {
public:
    ~PrimitiveCommandNode() override;
    void parse(Context& context) override;
    std::string toString() override;

private:
    std::string name_;
};
