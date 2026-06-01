#include "PrinterProxy.hpp"

PrinterProxy::PrinterProxy() {
}

PrinterProxy::PrinterProxy(const std::string& name_): name(name_) {
}

void PrinterProxy::setPrinterName(const std::string& name_) {
    std::lock_guard<std::mutex> guard(lock);
    if (real != nullptr) {
        real->setPrinterName(name_);
    }
    name = name_;
}

std::string PrinterProxy::getPrinterName() {
    return name;
}

void PrinterProxy::print(const std::string& string) {
    realize();
    real->print(string);
}

void PrinterProxy::realize() {
    std::lock_guard<std::mutex> guard(lock);
    if (real == nullptr) {
        real = new Printer(name);
    }
}
