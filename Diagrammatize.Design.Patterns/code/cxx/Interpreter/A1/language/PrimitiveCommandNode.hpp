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
    void execute() override;

private:
    std::string name_;
    std::unique_ptr<Executor> executor_;
};
