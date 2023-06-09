#include "FullBorder.hpp"
#include <sstream>

FullBorder::FullBorder(Display* display): Border(display) {
}

int FullBorder::getColumns() {
    return 1 + display->getColumns() + 1;
}

int FullBorder::getRows() {
    return 1 + display->getRows() + 1;
}

std::string FullBorder::getRowText(int row) {
    if (row == 0) {                                                 // 上边框
        return "+" + makeLine('-', display->getColumns()) + "+";
    } else if (row == display->getRows() + 1) {                      // 下边框
        return "+" + makeLine('-', display->getColumns()) + "+";
    } else {                                                        // 其他边框
        return "|" + display->getRowText(row - 1) + "|";
    }
}

std::string FullBorder::makeLine(char ch, int count) {
    return std::string(count, ch);
}
