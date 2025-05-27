#include "PrimitiveCommandNode.hpp"
#include "ParseException.hpp"

PrimitiveCommandNode::~PrimitiveCommandNode() {}

void PrimitiveCommandNode::parse(Context& context) {
    name_ = context.currentToken();
    context.skipToken(name_);
    if (name_ != "go" && name_ != "right" && name_ != "left") {
        throw ParseException(name_ + " is undefined");
    }
}

std::string PrimitiveCommandNode::toString() {
    return name_;
}
