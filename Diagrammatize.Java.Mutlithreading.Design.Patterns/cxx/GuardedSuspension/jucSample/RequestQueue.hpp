#pragma once

#include "Request.hpp"
#include "threadsafe_queue.hpp"

#include <memory>

class RequestQueue {
private:
    threadsafe_queue<Request> queue; 
    
public:
    Request getRequest() {
        auto request = queue.wait_and_pop();
        return *request;
    }
    
    void putRequest(const Request& request) {
        queue.push(request);
    }
};
