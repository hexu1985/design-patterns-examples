#pragma once

#include "Observer.hpp"

class DigitObserver: public Observer {
public:
    void update(NumberGenerator* generator) override;
};
