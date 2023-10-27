#include "Printer.hpp"

#include <iostream>
#include <chrono>
#include <thread>

Printer::Printer() {
    heavyJob("正在生成Printer的实例");
}

Printer::Printer(const std::string &name_): name(name_) {
    heavyJob("正在生成Printer的实例(" + name + ")");
}

void Printer::setPrinterName(const std::string& name_) {
    name = name_;
}

std::string Printer::getPrinterName() {
    return name;
}

void Printer::print(const std::string& string) {
    std::cout << "=== " << name << " ===" << std::endl;
    std::cout << string << std::endl;
}

void Printer::heavyJob(const std::string& msg) {
    std::cout << msg << std::flush;
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "." << std::flush;
    }
    std::cout << "结束。" << std::endl;
}
