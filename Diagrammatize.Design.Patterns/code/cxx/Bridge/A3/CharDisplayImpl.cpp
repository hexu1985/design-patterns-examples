#include "CharDisplayImpl.hpp"

#include <iostream>

CharDisplayImpl::CharDisplayImpl(char head_, char body_, char foot_): head(head_), body(body_), foot(foot_) {
}

void CharDisplayImpl::rawOpen() {
    std::cout << head;
}

void CharDisplayImpl::rawPrint() {
    std::cout << body;
}

void CharDisplayImpl::rawClose() {
    std::cout << foot << std::endl;
}

