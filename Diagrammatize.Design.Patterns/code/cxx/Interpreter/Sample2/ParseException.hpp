#pragma once

#include <stdexcept>

class ParseException : public std::logic_error {
public:
    ParseException(const std::string& what_arg): std::logic_error(what_arg) {}
};
