#include <iostream>
#include <thread>
#include <chrono>

#include "Gate.hpp"
#include "UserThread.hpp"

int main(int argc, char* argv[]) {
    std::cout << "Testing Gate, hit CTRL+C to exit." << std::endl;
    Gate gate;

    auto alice = UserThread(gate, "Alice", "Alaska");
    auto bobby = UserThread(gate, "Bobby", "Brazil");
    auto chris = UserThread(gate, "Chris", "Canada");
    
    alice.start();
    bobby.start();
    chris.start();

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
