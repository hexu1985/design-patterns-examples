#include "PrintBanner.hpp"


PrintBanner::PrintBanner(const std::string& string): Banner(string) {
}

PrintBanner::~PrintBanner() {
}

void PrintBanner::printWeak() {
    showWithParen();
}

void PrintBanner::printStrong() {
    showWithAster();
}
