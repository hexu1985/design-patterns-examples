#pragma once

#include <memory>

#include "Node.hpp"
#include "Context.hpp"

// <repeat command> ::= repeat <number> <command list>
class RepeatCommandNode: public Node {
public:
    ~RepeatCommandNode() override;
    void parse(Context& context) override;
    std::string toString() override;

private:
    int number_;
    std::unique_ptr<Node> commandListNode_;
};
