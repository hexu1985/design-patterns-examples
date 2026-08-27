#pragma once

#include "Request.hpp"

#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

class RequestQueue {
private:
    std::queue<Request> queue;
    std::mutex mtx;
    std::condition_variable cv;
    
public:
    Request getRequest() {
        std::unique_lock<std::mutex> lock(mtx);
        while (queue.empty()) {
            cv.wait(lock);
        }
        Request request = queue.front();
        queue.pop();
        return request;
    }
    
    void putRequest(const Request& request) {
        std::lock_guard<std::mutex> lock(mtx);
        queue.push(request);
        cv.notify_all();
    }
};
