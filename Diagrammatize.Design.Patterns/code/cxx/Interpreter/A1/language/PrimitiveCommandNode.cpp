#include "PrimitiveCommandNode.hpp"
#include "ParseException.hpp"
#include "ExecuteException.hpp"

PrimitiveCommandNode::~PrimitiveCommandNode() {}

void PrimitiveCommandNode::parse(Context& context) {
    name_ = context.currentToken();
    context.skipToken(name_);
    executor_ = context.createExecutor(name_);
}

std::string PrimitiveCommandNode::toString() {
    return name_;
}

void PrimitiveCommandNode::execute() {
    if (!executor_) {
        throw ExecuteException(name_ + ": is not defined");
    } else {
        executor_->execute();
    }
}
