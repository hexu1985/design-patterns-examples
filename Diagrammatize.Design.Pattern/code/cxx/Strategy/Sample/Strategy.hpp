#pragma once

#include "Hand.hpp"

class Strategy {
public:
    virtual ~Strategy();

    virtual Hand nextHand() = 0;
    virtual void study(bool win) = 0;
};
