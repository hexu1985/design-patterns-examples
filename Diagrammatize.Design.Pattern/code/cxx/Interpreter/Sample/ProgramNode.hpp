#pragma once

#include <string>

#include "Node.hpp"
#include "Context.hpp"
#include "CommandListNode.hpp"

class ProgramNode: public Node {
public:
    ~ProgramNode() override;
    void parse(Context& context) override;
    std::string toString() override;

private:
    std::unique_ptr<Node> commandListNode_;
};

