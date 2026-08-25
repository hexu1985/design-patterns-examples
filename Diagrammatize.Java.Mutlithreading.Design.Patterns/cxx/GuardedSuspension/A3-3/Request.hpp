#pragma once

#include <string>
#include <iostream>

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

// operator<< 重载
inline
std::ostream& operator<<(std::ostream& os, const Request& request) {
    os << request.toString();
    return os;
}
