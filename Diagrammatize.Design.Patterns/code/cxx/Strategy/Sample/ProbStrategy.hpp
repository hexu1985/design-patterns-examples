#pragma once

#include "Random.hpp"
#include "Strategy.hpp"

class ProbStrategy: public Strategy {
private:
    Random random;
    int prevHandValue = 0;
    int currentHandValue = 0;
    int history[3][3] = {
        { 1, 1, 1, },
        { 1, 1, 1, },
        { 1, 1, 1, },
    };

public:
    ProbStrategy(int seed);

    Hand nextHand() override;

    void study(bool win) override;

private:
    int getSum(int hv); 
};
