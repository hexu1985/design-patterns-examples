#pragma once

#include "Banner.hpp"
#include "Print.hpp"

class PrintBanner: private Banner, public Print {
public:
    PrintBanner(const std::string& string);
    ~PrintBanner() override;
    void printWeak() override;
    void printStrong() override;
};
