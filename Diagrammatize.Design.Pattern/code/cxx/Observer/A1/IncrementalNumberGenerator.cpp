#include "IncrementalNumberGenerator.hpp"

IncrementalNumberGenerator::IncrementalNumberGenerator(int start, int end_, int inc_):
    number(start), end(end_), inc(inc_) {
}

int IncrementalNumberGenerator::getNumber() {
    return number;
}

void IncrementalNumberGenerator::execute() {
    while (number < end) {
        notifyObservers();
        number += inc;
    }
}
