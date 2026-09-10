#pragma once

#include "limitedsize_queue.hpp"
#include "Request.hpp"
#include "LivenessException.hpp"
#include "thread_name.hpp"

class RequestQueue {
private:
    static constexpr auto TIMEOUT = std::chrono::milliseconds(3000);
    limitedsize_queue<Request> queue; 
    
public:
    Request getRequest() {
        Request request("");
        if (!queue.pop(request, TIMEOUT)) {
            throw LivenessException("thrown by " + current_thread::get_thread_name());
        }
        return request;
    }
    
    void putRequest(const Request& request) {
        if (!queue.push(request, TIMEOUT)) {
            throw LivenessException("thrown by " + current_thread::get_thread_name());
        }
    }
};
