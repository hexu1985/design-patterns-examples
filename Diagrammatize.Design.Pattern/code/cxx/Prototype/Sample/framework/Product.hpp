#pragma once

#include <string>

class Product {
public:
    virtual ~Product();

    virtual void use(const std::string& s) = 0;
    virtual Product* createClone() = 0;
};
