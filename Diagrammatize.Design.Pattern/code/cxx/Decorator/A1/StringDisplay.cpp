#include "StringDisplay.hpp"

StringDisplay::StringDisplay(const std::string& string_): string(string_) {
}

int StringDisplay::getColumns() {
    return string.length();
}

int StringDisplay::getRows() {
    return 1;
}

std::string StringDisplay::getRowText(int row) {
    if (row == 0) {
        return string;
    } else {
        return "";
    }
}
