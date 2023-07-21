#include "Support.hpp"
#include <iostream>

Support::Support(const std::string& name_): name(name_), next(nullptr) {
}

Support* Support::setNext(Support* next_) {
    next = next_;
    return next;
}

void Support::support(Trouble* trouble) {
    if (resolve(trouble)) {
        done(trouble);
    } else if (next != nullptr) {
        next->support(trouble);
    } else {
        fail(trouble);
    }
}

std::string Support::toString() const {
    return "[" + name + "]";
}

void Support::done(Trouble* trouble) {
    std::cout << *trouble << " is resolved by " << *this << "." << std::endl;
}

void Support::fail(Trouble* trouble) {
    std::cout << *trouble << " cannot be resolved." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Support& s) {
    os << s.toString();
    return os;
}
