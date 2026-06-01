#include "LimitSupport.hpp"

LimitSupport::LimitSupport(const std::string& name, int limit_): Support(name), limit(limit_) {
}

bool LimitSupport::resolve(Trouble* trouble) {
    if (trouble->getNumber() < limit) {
        return true;
    } else {
        return false;
    }
}

