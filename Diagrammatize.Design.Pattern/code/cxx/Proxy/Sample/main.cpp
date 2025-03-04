#include <iostream>
#include "PrinterProxy.hpp"

int main() {
    Printable* p = new PrinterProxy("Alice");
    std::cout << "现在的名字是" << p->getPrinterName() << "。" << std::endl;
    p->setPrinterName("Bob");
    std::cout << "现在的名字是" << p->getPrinterName() << "。" << std::endl;
    p->print("Hello, world.");
}
