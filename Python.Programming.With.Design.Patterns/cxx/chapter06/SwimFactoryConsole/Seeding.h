#pragma once

#include <vector>
#include "Swimmer.h"

class Seeding {
public:
    virtual std::vector<Swimmer> getSwimmers() = 0;
    virtual ~Seeding() {}
};

