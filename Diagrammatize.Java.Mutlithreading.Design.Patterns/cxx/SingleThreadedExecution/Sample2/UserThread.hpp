#pragma once

#include <thread>
#include "Gate.hpp"

class UserThread {
private:
    Gate* gate_=nullptr;
    const char* myname_="null";
    const char* myaddress_="null";

public:
    UserThread(Gate& gate, const char* myname, const char* myaddress):
        gate_(&gate), myname_(myname), myaddress_(myaddress) {
    }

    void start() {
        std::thread thr(&UserThread::run, this);
        thr.detach();
    }

    void run() {
        std::cout << myname_ << " BEGIN" << std::endl;
        while (true) {
            gate_->pass(myname_, myaddress_);
        }
    }
};

