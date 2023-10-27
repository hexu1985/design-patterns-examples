#pragma once

#include <string>
#include "Printable.hpp"

class Printer: public Printable {
private:
    std::string name;

public:
    Printer();
    Printer(const std::string &name);
    void setPrinterName(const std::string& name) override;
    std::string getPrinterName() override;
    void print(const std::string& string) override;

private:
    void heavyJob(const std::string& msg);
};
