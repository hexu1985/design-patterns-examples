#include "Entry.hpp"
#include "FileTreatmentException.hpp"

#include <sstream>
#include <iostream>
#include <list>

Entry::~Entry() {
}

Entry* Entry::add(Entry* entry) {
    throw FileTreatmentException{};
}

void Entry::printList() const {
    printList("");
}

std::string Entry::toString() const {
    std::ostringstream os;
    os << getName() << " (" << getSize() << ")";
    return os.str();
}

std::string Entry::getFullName() const {
    std::list<std::string> name_list;
    const Entry* entry = this;
    do {
        name_list.push_front(entry->getName());
        entry = entry->parent;
    } while (entry != nullptr);
    std::ostringstream fullname;
    for (const auto& name: name_list) {
        fullname << "/" << name;
    }
    return fullname.str();
}

std::ostream& operator<<(std::ostream& os, const Entry& entry) {
    os << entry.toString();
    return os;
}
