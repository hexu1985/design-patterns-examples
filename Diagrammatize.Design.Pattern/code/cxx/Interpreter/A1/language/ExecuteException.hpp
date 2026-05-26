#pragma once

#include <exception>
#include <string>

// ExecuteException 类
class ExecuteException : public std::exception {
private:
    std::string msg;

public:
    explicit ExecuteException(const std::string& msg) : msg(msg) {}

    const char* what() const noexcept override {
        return msg.c_str();
    }
};
