#include "MultiStringDisplay.hpp"

void MultiStringDisplay::add(const std::string& msg) {
    body.push_back(msg);
    updateColumn(msg);
}

int MultiStringDisplay::getColumns() {
    return columns;
}

int MultiStringDisplay::getRows() {
    return body.size();
}

std::string MultiStringDisplay::getRowText(int row) {
    return body[row];
}

void MultiStringDisplay::updateColumn(const std::string& msg) {
    if (msg.length() > columns) {
        columns = msg.length();
    }
    for (int row = 0; row < body.size(); row++) {
        int fills = columns - body[row].length();
        if (fills > 0) {
            body[row] = body[row] + spaces(fills);
        }
    }
}

std::string MultiStringDisplay::spaces(int count) {
    return std::string(count, ' ');
}
