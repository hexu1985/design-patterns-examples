#include "NumberGenerator.hpp"
#include "Observer.hpp"

NumberGenerator::~NumberGenerator() {
}

void NumberGenerator::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void NumberGenerator::deleteObserver(Observer* observer) {
    observers.remove(observer);
}

void NumberGenerator::notifyObservers() {
    for (auto o: observers) {
        o->update(this);
    }
}
