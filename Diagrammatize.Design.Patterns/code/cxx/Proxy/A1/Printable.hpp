#pragma once

#include <string>

class Printable {
public:
    virtual ~Printable();

    virtual void setPrinterName(const std::string& name) = 0;
    virtual std::string getPrinterName() = 0;
    virtual void print(const std::string& string) = 0;
};
