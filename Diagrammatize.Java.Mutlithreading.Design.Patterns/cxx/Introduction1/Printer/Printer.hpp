#pragma once

#include <iostream>

class Printer {
public:
    explicit Printer(const std::string& msg) : message(msg) {}

    void operator()() const {
        for (int i = 0; i < 10000; ++i) {
            std::cout << message;
        }
    }

private:
    std::string message;
};

