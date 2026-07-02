#pragma once

#include <thread>
#include <atomic>

class SecurityGate {
private:
    std::atomic<int> counter{0};

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
