#include "Request.hpp"
#include "RequestQueue.hpp"
#include "TalkThread.hpp"

int main() {
    RequestQueue requestQueue1;
    RequestQueue requestQueue2;
    requestQueue1.putRequest(Request("Hello"));

    TalkThread alice(requestQueue1, requestQueue2, "Alice");
    TalkThread bobby(requestQueue2, requestQueue1, "Bobby");

    alice.start();
    bobby.start();

    return 0;
}
