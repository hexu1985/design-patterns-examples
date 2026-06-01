#include "CommandNode.hpp"
#include "PrimitiveCommandNode.hpp"
#include "RepeatCommandNode.hpp"

CommandNode::~CommandNode() {}

void CommandNode::parse(Context& context) {
    if (context.currentToken() == "repeat") {
        node_.reset(new RepeatCommandNode());
        node_->parse(context);
    } else {
        node_.reset(new PrimitiveCommandNode());
        node_->parse(context);
    }
}

std::string CommandNode::toString() {
    return node_->toString();
}
