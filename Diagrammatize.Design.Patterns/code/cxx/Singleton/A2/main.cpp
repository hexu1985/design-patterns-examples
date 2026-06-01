#include "Triple.hpp"
#include <iostream>

int main() {
    std::cout << "Start." << std::endl;
    for (int i = 0; i < 9; i++) {
        Triple& triple = Triple::getInstance(i % 3);
        std::cout << i << ":" << triple << std::endl;
    }
    std::cout << "End." << std::endl;
}
