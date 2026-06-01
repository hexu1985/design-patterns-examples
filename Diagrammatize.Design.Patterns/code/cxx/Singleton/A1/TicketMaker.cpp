#include "TicketMaker.hpp"

TicketMaker TicketMaker::singleton{};

TicketMaker& TicketMaker::getInstance() {
    return singleton;
}

int TicketMaker::getNextTicketNumber() {
    return ticket++;
}
