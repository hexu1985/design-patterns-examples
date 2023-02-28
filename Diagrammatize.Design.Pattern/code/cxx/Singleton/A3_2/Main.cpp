#include "Singleton.hpp"
#include <thread>
#include <vector>
#include <iostream>

void run() {
    Singleton& obj = Singleton::getInstance();
    std::cout << std::this_thread::get_id() << ": obj = " << (void *) &obj << std::endl; 
}

int main() {
    std::cout << "Start." << std::endl;
    std::vector<std::thread> thread_list;
    thread_list.push_back(std::thread{&run});
    thread_list.push_back(std::thread{&run});
    thread_list.push_back(std::thread{&run});
    for (auto &t : thread_list) {
        t.join();
    }
    std::cout << "End." << std::endl;
}
