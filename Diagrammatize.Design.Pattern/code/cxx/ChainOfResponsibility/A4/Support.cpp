#include "Support.hpp"
#include <iostream>

Support::Support(const std::string& name_): name(name_), next(nullptr) {
}

Support* Support::setNext(Support* next_) {
    next = next_;
    return next;
}

void Support::support(Trouble* trouble) {
    for (Support* obj = this; true; obj = obj->next) {
        if (obj->resolve(trouble)) {
            obj->done(trouble);
            break;
        } else if (obj->next == nullptr) {
            obj->fail(trouble);
            break;
        }
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
