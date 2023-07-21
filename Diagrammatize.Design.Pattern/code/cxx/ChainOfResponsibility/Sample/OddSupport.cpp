#include "OddSupport.hpp"

OddSupport::OddSupport(const std::string& name) : Support(name) {
}

bool OddSupport::resolve(Trouble* trouble) {
    if (trouble->getNumber() % 2 == 1) {
        return true;
    } else {
        return false;
    }
}

