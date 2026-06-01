#pragma once

#include "Observer.hpp"

class GraphObserver: public Observer {
public:
    void update(NumberGenerator* generator) override;
};
