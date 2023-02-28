#pragma once

#include <atomic>

class TicketMaker {
private:
    std::atomic<int> ticket{1000};
    static TicketMaker singleton;

    TicketMaker() = default;
    TicketMaker(const TicketMaker&) = delete;
    TicketMaker& operator=(const TicketMaker&) = delete;

public:
    static TicketMaker& getInstance();
    int getNextTicketNumber();
};
