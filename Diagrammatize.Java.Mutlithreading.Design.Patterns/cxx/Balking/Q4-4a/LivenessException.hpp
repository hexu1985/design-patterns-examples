#pragma once

#include <stdexcept>
#include <string>

class LivenessException : public std::runtime_error {
public:
    explicit LivenessException(const std::string& message) 
        : std::runtime_error(message) {}
};

