#pragma once

#include <string>

class Request {
private:
    const std::string name;
    
public:
    Request(const std::string& name) : name(name) {}
    
    const std::string& getName() const {
        return name;
    }
    
    std::string toString() const {
        return "[ Request " + name + " ]";
    }
};
