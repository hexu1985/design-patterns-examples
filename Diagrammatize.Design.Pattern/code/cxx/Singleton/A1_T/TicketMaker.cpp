#include "TicketMaker.hpp"
#include <iostream>

int TicketMaker::getNextTicketNumber() {
    return ticket++;
}

template class Singleton<TicketMaker>;
