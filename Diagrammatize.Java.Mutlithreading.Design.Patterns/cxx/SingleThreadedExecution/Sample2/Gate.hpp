#pragma once 

#include <string>
#include <iostream>
#include <sstream>
#include <mutex>

class Gate {
private:
    int counter_ = 0;
    const char* name_ = "Nobody";
    const char* address_ = "Nowhere";
    std::mutex mutex_;

public:
    void pass(const char* name, const char* address) {
        std::lock_guard<std::mutex> lck(mutex_);
        counter_++;
        name_ = name;
        address_ = address;
        check();
    }

    std::string toString() {
        std::lock_guard<std::mutex> lck(mutex_);
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

