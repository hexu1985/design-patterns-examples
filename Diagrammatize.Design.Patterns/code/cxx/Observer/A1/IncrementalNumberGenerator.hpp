#pragma once

#include "NumberGenerator.hpp"

class IncrementalNumberGenerator: public NumberGenerator {
private:
    int number;
    int end;
    int inc;

public:
    IncrementalNumberGenerator(int start, int end, int inc);

    int getNumber() override;
    
    void execute() override;
};
