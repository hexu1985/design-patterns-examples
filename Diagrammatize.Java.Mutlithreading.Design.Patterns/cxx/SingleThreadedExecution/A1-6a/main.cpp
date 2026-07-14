#include <iostream>
#include <thread>
#include <chrono>

#include "Tool.hpp"
#include "EaterThread.hpp"

int main() {
    std::cout << "Testing EaterThread, hit CTRL+C to exit." << std::endl;
    
    Tool spoon("Spoon");
    Tool fork("Fork");
    
    EaterThread alice("Alice", spoon, fork);
    EaterThread bobby("Bobby", spoon, fork);
    
    alice.start();
    bobby.start();
    
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}
