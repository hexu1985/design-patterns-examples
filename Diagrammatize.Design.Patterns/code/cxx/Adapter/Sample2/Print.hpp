#pragma once

class Print {
public:
    virtual ~Print();

    virtual void printWeak() = 0;
    virtual void printStrong() = 0;
};
