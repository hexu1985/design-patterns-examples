#pragma once

#include "Request.hpp"
#include "RequestQueue.hpp"

#include <thread>
#include <random>
#include <chrono>
#include <string>
#include <iostream>

class ServerThread {
private:
    RequestQueue& requestQueue;
    std::string threadName;
    std::thread thread;
    std::mt19937 random;
    
public:
    ServerThread(RequestQueue& requestQueue, const std::string& name, long seed)
        : requestQueue(requestQueue), threadName(name), random(seed) {}

    ~ServerThread() {
        join();
    }
    
    void run() {
        for (int i = 0; i < 1000; i++) {
            Request request = requestQueue.getRequest();
            std::cout << threadName << " handles  " << request.toString() << std::endl;
            
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
