#pragma once

#include "framework/Product.hpp"

class MessageBox : public Product {
private:
    char decochar;

public:
    MessageBox(char decochar_);
    ~MessageBox() override;

    void use(const std::string& s) override;
    MessageBox* createClone() override;
};
