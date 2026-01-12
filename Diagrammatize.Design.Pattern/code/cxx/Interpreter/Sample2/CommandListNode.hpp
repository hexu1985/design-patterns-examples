#pragma once

#include <string>
#include <memory>
#include <vector>

#include "Node.hpp"
#include "Context.hpp"

// <command list> ::= <command>* end
class CommandListNode: public Node {
public:
    ~CommandListNode() override;
    void parse(Context& context) override;
    std::string toString() override;

private:
    std::vector<std::unique_ptr<Node>> list_;
};
