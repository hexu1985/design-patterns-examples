#pragma once

#include <string>
#include <mutex>

class Tool {
private:
    std::string name;
    std::mutex mtx;
    
public:
    Tool(const std::string& name) : name(name) {}
    
    std::string toString() const {
        return "[ " + name + " ]";
    }

    std::mutex& getMutex() {
        return mtx;
    }
};
