#include "CommandListNode.hpp"

#include <sstream>

#include "CommandNode.hpp"
#include "ParseException.hpp"

CommandListNode::~CommandListNode() {}

void CommandListNode::parse(Context& context) {
    while (true) {
        if (context.currentToken().empty()) {
            throw ParseException("Missing 'end'");
        } else if (context.currentToken() == "end") {
            context.skipToken("end");
            break;
        } else {
            auto commandNode = std::unique_ptr<Node>(new CommandNode());
            commandNode->parse(context);
            list_.push_back(std::move(commandNode));
        }
    }
}

std::string CommandListNode::toString() {
    int n = list_.size();
    std::stringstream ss;
    ss << "[";
    for (int i = 0; i < n; i++) {
        ss << list_[i]->toString();
        if (i != n-1) {
            ss << " ";
        }
    }
    ss << "]";

    return ss.str();
}
