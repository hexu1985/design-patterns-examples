#pragma once

#include "Banner.hpp"
#include "Print.hpp"

class PrintBanner: public Print {
private:
    Banner banner;

public:
    PrintBanner(const std::string& string);
    ~PrintBanner() override;
    void printWeak() override;
    void printStrong() override;
};
