#pragma once

#include "Request.hpp"
#include "InterruptedException.hpp"

#include <atomic>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

class RequestQueue {
private:
    std::queue<Request> queue;
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<bool> interrupted{false};
    
public:
    void interrupt() {
        interrupted = true;
        cv.notify_all();
    }

    void reset_interrupt() {
        interrupted = false;
    }

    Request getRequest() {
        std::unique_lock<std::mutex> lock(mtx);
        while (queue.empty() && !interrupted) {
            cv.wait(lock);
        }

        if (interrupted) {
            throw InterruptedException{}; 
        }

        Request request = queue.front();
        queue.pop();
        return request;
    }
    
    void putRequest(const Request& request) {
        std::lock_guard<std::mutex> lock(mtx);

        if (interrupted) {
            throw InterruptedException{}; 
        }

        queue.push(request);
        cv.notify_all();
    }
};
