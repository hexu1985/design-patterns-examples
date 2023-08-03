#pragma once

#include "Random.hpp"
#include "NumberGenerator.hpp"

class RandomNumberGenerator: public NumberGenerator {
private:
    int number;
    Random random;

public:
    int getNumber() override;
    void execute() override;
};
