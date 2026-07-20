#include <iostream>
#include <memory>
#include <chrono>

#include "Person.hpp"
#include "PrintPersonThread.hpp"

int main() {
    Person alice{"Alice", "Alaska"};
    
    PrintPersonThread printer1(alice);
    PrintPersonThread printer2(alice);
    PrintPersonThread printer3(alice);
    
    printer1.start();
    printer2.start();
    printer3.start();
    
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
