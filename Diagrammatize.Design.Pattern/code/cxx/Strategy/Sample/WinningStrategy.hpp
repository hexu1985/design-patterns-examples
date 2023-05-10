#pragma once

#include "Random.hpp"
#include "Strategy.hpp"

class WinningStrategy: public Strategy {
private:
    Random random;
    bool won = false;
    Hand prevHand;

public:
    WinningStrategy(int seed);

    Hand nextHand() override;

    void study(bool win) override;
};

