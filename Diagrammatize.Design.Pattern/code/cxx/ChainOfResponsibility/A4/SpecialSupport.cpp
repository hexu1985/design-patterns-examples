#include "SpecialSupport.hpp"

SpecialSupport::SpecialSupport(const std::string& name, int number_) : Support(name), number(number_) {
}

bool SpecialSupport::resolve(Trouble* trouble) {
    if (trouble->getNumber() == number) {
        return true;
    } else {
        return false;
    }
}
