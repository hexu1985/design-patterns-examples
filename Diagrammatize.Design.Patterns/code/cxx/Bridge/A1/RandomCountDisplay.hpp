#pragma once

#include "CountDisplay.hpp"
#include "Random.hpp"

class RandomCountDisplay: public CountDisplay {
private:
    Random random;

public:
    RandomCountDisplay(DisplayImpl* impl);

    void randomDisplay(int times); 
};
