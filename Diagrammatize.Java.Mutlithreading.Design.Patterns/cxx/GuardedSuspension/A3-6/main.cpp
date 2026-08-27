#include "ClientThread.hpp"
#include "ServerThread.hpp"
#include "Request.hpp"
#include "RequestQueue.hpp"

int main() {
    RequestQueue requestQueue;
    
    ClientThread alice(requestQueue, "Alice", 3141592L);
    ServerThread bobby(requestQueue, "Bobby", 6535897L);
    
    alice.start();
    bobby.start();
    
    // 等待约10秒
    std::this_thread::sleep_for(std::chrono::seconds(10));

    // 调用interrupt方法
    std::cout << "***** calling interrupt *****" << std::endl;
    alice.interrupt();
    bobby.interrupt();

    return 0;
}
