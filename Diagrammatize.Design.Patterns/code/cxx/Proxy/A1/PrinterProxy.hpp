#pragma once

#include "Printable.hpp"
#include <mutex>

class PrinterProxy: public Printable {
private:
    std::string name;
    Printable* real=nullptr;
    std::string className;
    std::mutex lock;

public:
    PrinterProxy(const std::string& name, const std::string& className);

    void setPrinterName(const std::string& name) override;
    std::string getPrinterName() override;
    void print(const std::string& string) override;

private:
    void realize();
};
