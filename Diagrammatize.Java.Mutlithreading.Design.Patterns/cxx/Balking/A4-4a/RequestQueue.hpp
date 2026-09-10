#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <thread>

#include "Request.hpp"
#include "LivenessException.hpp"
#include "thread_name.hpp"

class RequestQueue {
private:
    static constexpr auto TIMEOUT = std::chrono::milliseconds(3000);
    std::queue<Request> queue;
    std::mutex mtx;
    std::condition_variable cv;

public:
    Request getRequest() {
        std::unique_lock<std::mutex> lock(mtx);
        auto start = std::chrono::steady_clock::now(); // 开始时间
        
        while (queue.empty()) {
            auto now = std::chrono::steady_clock::now(); // 当前时间
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
            auto rest = TIMEOUT - elapsed; // 剩余的等待时间
            
            if (rest <= std::chrono::milliseconds(0)) {
                throw LivenessException("thrown by " + current_thread::get_thread_name());
            }
            
            cv.wait_for(lock, rest);
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
