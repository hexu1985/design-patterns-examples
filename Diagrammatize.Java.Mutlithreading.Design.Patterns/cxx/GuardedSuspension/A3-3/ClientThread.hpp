#pragma once

#include "Request.hpp"
#include "RequestQueue.hpp"
#include "thread_name.hpp"

#include <thread>
#include <random>
#include <chrono>
#include <string>
#include <iostream>

class ClientThread {
private:
    RequestQueue& requestQueue;
    std::string threadName;
    std::thread thread;
    std::mt19937 random;
    
public:
    ClientThread(RequestQueue& requestQueue, const std::string& name, long seed)
        : requestQueue(requestQueue), threadName(name), random(seed) {}

    ~ClientThread() {
        join();
    }
    
    void run() {
        current_thread::set_thread_name(threadName);
        for (int i = 0; i < 100; i++) {
            Request request("No." + std::to_string(i));
            std::cout << threadName << " requests " << request.toString() << std::endl;
            requestQueue.putRequest(request);
            
            std::uniform_int_distribution<int> dist(0, 999);
            int sleepTime = dist(random);
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }
    }
    
    void start() {
        thread = std::thread([this]() { this->run(); });
    }

    void join() {
        if (thread.joinable()) {
            thread.join();
        }
    }
};
