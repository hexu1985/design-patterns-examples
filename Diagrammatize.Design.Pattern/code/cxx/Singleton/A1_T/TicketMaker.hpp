#pragma once

#include "Singleton.hpp"
#include <atomic>

class TicketMaker: public Singleton<TicketMaker> {
private:
    std::atomic<int> ticket{1000};

    friend class Singleton<TicketMaker>;
    TicketMaker() = default;

public:
    int getNextTicketNumber();
};

extern template class Singleton<TicketMaker>;
