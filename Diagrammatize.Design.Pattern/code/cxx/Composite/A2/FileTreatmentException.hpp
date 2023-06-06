#pragma once

#include <string>
#include <stdexcept>

class FileTreatmentException: public std::runtime_error {
public:
    FileTreatmentException(const std::string& msg=""): std::runtime_error(msg) {}
};
