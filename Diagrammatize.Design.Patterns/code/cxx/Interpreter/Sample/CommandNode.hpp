#pragma once

#include <string>
#include <memory>

#include "Node.hpp"
#include "Context.hpp"

// <command> ::= <repeat command> | <primitive command>
class CommandNode: public Node {
public:
    ~CommandNode() override;
    void parse(Context& context) override;
    std::string toString() override;

private:
    std::unique_ptr<Node> node_;
};
