#pragma once

#include "CountDisplay.hpp"

class IncreaseDisplay: public CountDisplay {
private:
    int step;   // 递增步长

public:
    IncreaseDisplay(DisplayImpl* impl, int step);

    void increaseDisplay(int level);
};
