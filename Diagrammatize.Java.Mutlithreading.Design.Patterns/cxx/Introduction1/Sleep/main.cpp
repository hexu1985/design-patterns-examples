#include <iostream>
#include <thread>
#include <chrono>

int main() {
    for (int i = 0; i < 10; i++) {
        std::cerr << "Good!";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
