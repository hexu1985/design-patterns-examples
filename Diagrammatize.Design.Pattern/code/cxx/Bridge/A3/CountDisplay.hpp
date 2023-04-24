#pragma once

#include "Display.hpp"

class CountDisplay: public Display {
public:
    CountDisplay(DisplayImpl* impl);

    void multiDisplay(int times);        // 循环显示times次
};
