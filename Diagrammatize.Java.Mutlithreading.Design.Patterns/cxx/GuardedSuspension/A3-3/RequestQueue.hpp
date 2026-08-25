#pragma once

#include "Request.hpp"
#include "print_queue.hpp"
#include "thread_name.hpp"

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
            std::cout << current_thread::get_thread_name() << ": wait() begins, queue = " << queue << std::endl;
            cv.wait(lock);
            std::cout << current_thread::get_thread_name() << ": wait() ends,   queue = " << queue << std::endl;
        }
        Request request = queue.front();
        queue.pop();
        return request;
    }
    
    void putRequest(const Request& request) {
        std::lock_guard<std::mutex> lock(mtx);
        queue.push(request);
        std::cout << current_thread::get_thread_name() << ": notifyAll() begins, queue = " << queue << std::endl;
        cv.notify_all();
        std::cout << current_thread::get_thread_name() << ": notifyAll() ends,   queue = " << queue << std::endl;
    }
};
