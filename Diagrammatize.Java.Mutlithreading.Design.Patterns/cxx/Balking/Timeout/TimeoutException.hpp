#pragma once

#include <stdexcept>
#include <string>

// 对应 Java 的 TimeoutException
class TimeoutException : public std::runtime_error {
public:
    explicit TimeoutException(const std::string& msg) : std::runtime_error(msg) {}
};

