#include "Manager.hpp"

void Manager::register_(const std::string& name, Product* proto) {
    showcase[name] = proto;
}

Product* Manager::create(const std::string& protoname) {
    Product* p = showcase.at(protoname);
    return p->createClone();
}

