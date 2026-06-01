#include "UpDownBorder.hpp"

#include <sstream>

UpDownBorder::UpDownBorder(Display* display, char ch): Border(display), borderChar(ch) {
}

int UpDownBorder::getColumns() {
    return display->getColumns();
}

int UpDownBorder::getRows() {
    return 1 + display->getRows() + 1;
}

std::string UpDownBorder::getRowText(int row) {
    if (row == 0 || row == getRows() - 1) {
        return makeLine(borderChar, getColumns());
    } else {
        return display->getRowText(row - 1);
    }
}
    
std::string UpDownBorder::makeLine(char ch, int count) {
    return std::string(count, ch);
}
