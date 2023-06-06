#include "Directory.hpp"

#include <iostream>

Directory::Directory(const std::string& name_): name(name_) {
}

std::string Directory::getName() const {
    return name;
}

int Directory::getSize() const {
    int size = 0;
    for (auto entry: directory) {
        size += entry->getSize();
    }
    return size;
}

Entry* Directory::add(Entry* entry) {
    directory.push_back(entry);
    return this;
}

void Directory::printList(const std::string& prefix) const {
    std::cout << prefix << "/" << *this << std::endl;
    for (auto entry: directory) {
        entry->printList(prefix + "/" + name);
    }
}
