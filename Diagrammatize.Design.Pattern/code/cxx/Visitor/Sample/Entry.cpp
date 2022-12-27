#include "Entry.hpp"
#include <iostream>

Entry::~Entry() {}

std::ostream& operator<<(std::ostream& out, Entry& entry) {
    out << entry.getName() << " (" << entry.getSize() << ")";
    return out;
}
