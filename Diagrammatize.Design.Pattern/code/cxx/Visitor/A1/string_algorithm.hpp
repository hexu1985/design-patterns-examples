#pragma once

#include <string>

static bool ends_with(const std::string& input, const std::string& test) {
    return input.rfind(test) == (input.length() - test.length());
}
