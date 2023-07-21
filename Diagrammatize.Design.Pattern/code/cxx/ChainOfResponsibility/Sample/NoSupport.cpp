#include "NoSupport.hpp"

NoSupport::NoSupport(const std::string& name): Support(name) {
}

bool NoSupport::resolve(Trouble* trouble) {
    return false;
}
