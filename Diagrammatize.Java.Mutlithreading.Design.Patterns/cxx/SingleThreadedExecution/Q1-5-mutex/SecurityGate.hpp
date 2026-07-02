#pragma once

#include <thread>
#include <mutex>

class SecurityGate {
private:
    int counter = 0;
    mutable std::mutex mutex;

public:
    void enter() {
        std::lock_guard<std::mutex> lck(mutex);
        counter++;
    }

    void exit() {
        std::lock_guard<std::mutex> lck(mutex);
        counter--;
    }

    int getCounter() const {
        std::lock_guard<std::mutex> lck(mutex);
        return counter;
    }
};
