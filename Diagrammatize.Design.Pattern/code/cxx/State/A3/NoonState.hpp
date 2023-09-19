#pragma once

#include <string>

#include "State.hpp"

class NoonState: public State {
private:
    NoonState();

public:
    static State* getInstance();

    void doClock(Context* context, int hour) override;

    void doUse(Context* context) override;

    void doAlarm(Context* context) override;

    void doPhone(Context* context) override;

    std::string toString() const override;
};
