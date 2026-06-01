#include "SideBorder.hpp"

SideBorder::SideBorder(Display* display, char ch):Border(display), borderChar(ch) {
}

int SideBorder::getColumns() {
    return 1 + display->getColumns() + 1;
}

int SideBorder::getRows() {
    return display->getRows();
}

std::string SideBorder::getRowText(int row) {
    return borderChar + display->getRowText(row) + borderChar;
}
