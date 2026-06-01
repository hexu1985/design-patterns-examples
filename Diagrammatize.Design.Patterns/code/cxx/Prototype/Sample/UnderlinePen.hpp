#pragma once

#include "framework/Product.hpp"

class UnderlinePen : public Product {
private:
    char ulchar;

public:
    UnderlinePen(char ulchar_);
    ~UnderlinePen() override;

    void use(const std::string& s) override; 
    UnderlinePen* createClone() override;
};
