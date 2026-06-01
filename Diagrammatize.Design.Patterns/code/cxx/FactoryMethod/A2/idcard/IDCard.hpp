#pragma once

#include "framework/Product.hpp"
#include <string>

class IDCard : public Product {
private:
    std::string owner;
    int serial;

public:
    IDCard(const std::string& owner, int serial);

    void use() override;

    std::string getOwner();

    int getSerial();
};
