#pragma once

class Executor {
public:
    virtual ~Executor() = default;
    virtual void execute() = 0;
};

