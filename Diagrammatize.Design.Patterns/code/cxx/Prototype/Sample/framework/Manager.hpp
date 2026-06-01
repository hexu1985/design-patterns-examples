#pragma once

#include "Product.hpp"
#include <string>
#include <unordered_map>

class Manager {
private:
    std::unordered_map<std::string, Product*> showcase;

public:
    void register_(const std::string& name, Product* proto);
    Product* create(const std::string& protoname);
};
