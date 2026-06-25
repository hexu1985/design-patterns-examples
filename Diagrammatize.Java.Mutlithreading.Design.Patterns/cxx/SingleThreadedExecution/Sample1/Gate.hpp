#pragma once 

#include <string>
#include <iostream>
#include <sstream>

class Gate {
private:
    int counter_ = 0;
    const char* name_ = "Nobody";
    const char* address_ = "Nowhere";

public:
    void pass(const char* name, const char* address) {
        counter_++;
        name_ = name;
        address_ = address;
        check();
    }

    std::string toString() {
        std::ostringstream out;
        out << "No." << counter_ << ": " << name_ << ", " << address_;
        return out.str();
    }

private:
    void check() {
        if (name_[0] != address_[0]) {
            std::cout << "***** BROKEN ***** " << toString() << std::endl;
        }
    }
};

