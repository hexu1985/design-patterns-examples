#pragma once

#include <thread>

class SecurityGate {
private:
    int counter = 0;

public:
    void enter() {
        counter++;
    }

    void exit() {
        counter--;
    }

    int getCounter() const {
        return counter;
    }
};
