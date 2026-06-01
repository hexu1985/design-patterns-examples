#include "FileDisplayImpl.hpp"

#include <iostream>

FileDisplayImpl::FileDisplayImpl(const std::string& filename_): filename(filename_) {
}

void FileDisplayImpl::rawOpen() {
    reader.open(filename);
    std::cout << "=-=-=-=-=-= " << filename << " =-=-=-=-=-=" << std::endl; // 装饰框
}

void FileDisplayImpl::rawPrint() {
    std::string line;
    reader.clear();
    reader.seekg(0, reader.beg);
    while (std::getline(reader, line)) {
        std::cout << "> " << line << "\n";
    }
}

void FileDisplayImpl::rawClose() {
    std::cout << "=-=-=-=-=-= " << std::endl; // 装饰框
    reader.close();
}
