#pragma once

#include <string>
#include <iostream>

class Context;

class State {
public:
    virtual ~State();
    virtual void doClock(Context* context, int hour) = 0;
    virtual void doUse(Context* context) = 0;
    virtual void doAlarm(Context* context) = 0;
    virtual void doPhone(Context* context) = 0;
    virtual std::string toString() const = 0;
};

inline
std::ostream& operator<<(std::ostream& out, const State& state) {
    out << state.toString();
    return out;
}
