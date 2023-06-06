#include "Entry.hpp"
#include "FileTreatmentException.hpp"

#include <sstream>
#include <iostream>

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

std::ostream& operator<<(std::ostream& os, const Entry& entry) {
    os << entry.toString();
    return os;
}
