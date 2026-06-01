#include "PrintBanner.hpp"


PrintBanner::PrintBanner(const std::string& string): banner(string) {
}

PrintBanner::~PrintBanner() {
}

void PrintBanner::printWeak() {
    banner.showWithParen();
}

void PrintBanner::printStrong() {
    banner.showWithAster();
}
