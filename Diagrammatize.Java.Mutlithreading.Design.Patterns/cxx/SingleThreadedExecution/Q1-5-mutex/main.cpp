#include <iostream>
#include <vector>
#include <memory>

#include "SecurityGate.hpp"
#include "CrackerThread.hpp"

int main() {
    std::cout << "Testing SecurityGate..." << std::endl;
    
    for (int trial = 0; true; ++trial) {
        SecurityGate gate;
        std::vector<std::shared_ptr<CrackerThread>> threads;
        
        // 启动5个CrackerThread
        for (int i = 0; i < 5; ++i) {
            std::shared_ptr<CrackerThread> cracker = std::make_shared<CrackerThread>(gate);
            threads.push_back(cracker);
            cracker->start();
        }
        
        // 等待所有线程终止
        for (auto& t : threads) {
            t->join();
        }
        
        // 确认
        if (gate.getCounter() == 0) {
            std::cout << ".";
            std::cout.flush();
        } else {
            std::cout << "\nSecurityGate is NOT safe!" << std::endl;
            std::cout << "getCounter() == " << gate.getCounter() << std::endl;
            std::cout << "trial = " << trial << std::endl;
            break;
        }
    }
    
    return 0;
}
