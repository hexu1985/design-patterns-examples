#include "Bank.hpp"
#include "ClientThread.hpp"

int main() {
    Bank bank("A Bad Bank", 1000);
    ClientThread client1(bank);
    ClientThread client2(bank);

    client1.start();
    client2.start();
    
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}
