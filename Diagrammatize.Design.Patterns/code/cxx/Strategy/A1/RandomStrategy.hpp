#pragma once

#include "Random.hpp"
#include "Strategy.hpp"

class RandomStrategy: public Strategy {
private:
    Random random;

public:
    RandomStrategy(int seed);

    Hand nextHand() override;

    void study(bool win) override;
};

