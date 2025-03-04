#include "TicketMaker.hpp"
#include <iostream>

int main() {
    std::cout << "Start." << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i << ":" 
            << TicketMaker::getInstance().getNextTicketNumber() 
            << std::endl;
    }
    std::cout << "End." << std::endl;
}
