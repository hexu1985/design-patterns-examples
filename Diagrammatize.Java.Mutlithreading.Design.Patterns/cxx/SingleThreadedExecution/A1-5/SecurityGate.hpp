#pragma once

#include <thread>

class SecurityGate {
private:
    int counter = 0;

public:
    void enter() {
        int currentCounter = counter;
        std::this_thread::yield();
        counter = currentCounter + 1;
    }

    void exit() {
        int currentCounter = counter;
        std::this_thread::yield();
        counter = currentCounter - 1;
    }

    int getCounter() const {
        return counter;
    }
};
