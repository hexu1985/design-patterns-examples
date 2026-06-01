#include "PrinterProxy.hpp"
#include "PrinterManager.hpp"
#include <iostream>

PrinterProxy::PrinterProxy(const std::string& name_, const std::string& className_): 
    name(name_), className(className_) {
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
        real = PrinterManager::newInstance(className);
        if (real) {
            real->setPrinterName(name);
        } else {
            std::cout << "没有找到 " << className << " 类。" << std::endl;
        }
    }
}
