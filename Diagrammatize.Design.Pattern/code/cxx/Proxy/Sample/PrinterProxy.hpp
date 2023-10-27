#pragma once

#include "Printable.hpp"
#include "Printer.hpp"
#include <mutex>

class PrinterProxy: public Printable {
private:
    std::string name;
    Printer* real=nullptr;
    std::mutex lock;

public:
    PrinterProxy();
    PrinterProxy(const std::string& name);

    void setPrinterName(const std::string& name) override;
    std::string getPrinterName() override;
    void print(const std::string& string) override;

private:
    void realize();
};
