#include "ProgramNode.hpp"

ProgramNode::~ProgramNode() {}

void ProgramNode::parse(Context& context) {
    context.skipToken("program");
    commandListNode_.reset(new CommandListNode());
    commandListNode_->parse(context);
}

std::string ProgramNode::toString() {
    return "[program " + commandListNode_->toString() + "]";
}
