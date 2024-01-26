#include "MacroCommand.hpp"

void MacroCommand::execute() {
    for (auto cmd : commands) {
        cmd->execute();
    }
}

void MacroCommand::append(std::shared_ptr<Command> cmd) {
    if (cmd.get() != this) {
        commands.push_back(cmd);
    }
}

void MacroCommand::undo() {
    if (!commands.empty()) {
        commands.pop_back();
    }
}

void MacroCommand::clear() {
    commands.clear();
}
