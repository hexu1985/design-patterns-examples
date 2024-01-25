#pragma once

#include <vector>
#include <memory>
#include "Command.hpp"

class MacroCommand: public Command {
private:
    std::vector<std::shared_ptr<Command>> commands;

public:
    void execute() override;

    void append(std::shared_ptr<Command> cmd);
    void undo();
    void clear();
};
