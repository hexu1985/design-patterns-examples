#pragma once

#include "Request.hpp"
#include "RequestQueue.hpp"

#include <string>
#include <thread>
#include <iostream>

class TalkThread {
private:
    RequestQueue& input;
    RequestQueue& output;
    std::string name;
    std::thread thread;

public:
    TalkThread(RequestQueue& input, RequestQueue& output, const std::string& name)
        : input(input), output(output), name(name) {}

    ~TalkThread() {
        join();
    }

    void run() {
        std::cout << name << ":BEGIN" << std::endl;
        for (int i = 0; i < 20; i++) {
            // 接收对方的请求
            Request request1 = input.getRequest();
            std::cout << name << " gets  " << request1.toString() << std::endl;

            // 加上一个(!)再返给对方
            Request request2(request1.getName() + "!");
            std::cout << name << " puts  " << request2.toString() << std::endl;
            output.putRequest(request2);
        }
        std::cout << name << ":END" << std::endl;
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
