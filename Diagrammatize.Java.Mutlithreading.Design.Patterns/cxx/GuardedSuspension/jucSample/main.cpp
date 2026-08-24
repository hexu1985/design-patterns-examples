#include "ClientThread.hpp"
#include "ServerThread.hpp"
#include "Request.hpp"
#include "RequestQueue.hpp"

int main() {
    RequestQueue requestQueue;
    
    ClientThread client(requestQueue, "Alice", 3141592L);
    ServerThread server(requestQueue, "Bobby", 6535897L);
    
    client.start();
    server.start();
    
    return 0;
}
