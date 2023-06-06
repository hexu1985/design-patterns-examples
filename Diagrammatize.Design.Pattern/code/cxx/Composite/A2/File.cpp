#include "File.hpp"
#include <iostream>

File::File(const std::string& name_, int size_): name(name_), size(size_) {
}

std::string File::getName() const {
    return name;
}

int File::getSize() const {
    return size;
}

void File::printList(const std::string& prefix) const {
    std::cout << prefix << "/" << *this << std::endl;
}
