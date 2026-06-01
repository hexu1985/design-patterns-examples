#include "RepeatCommandNode.hpp"
#include <sstream>

#include "CommandListNode.hpp"

RepeatCommandNode::~RepeatCommandNode() {}

void RepeatCommandNode::parse(Context& context) {
    context.skipToken("repeat");
    number_ = context.currentNumber();
    context.nextToken();
    commandListNode_.reset(new CommandListNode());
    commandListNode_->parse(context);
}

std::string RepeatCommandNode::toString() {
    std::stringstream ss;
    ss << "[repeat " << number_ << " " 
        << commandListNode_->toString() << "]";
    return ss.str();
}
