#pragma once

#include <unordered_map>
#include "framework/Factory.hpp"

class IDCardFactory : public Factory {
private:
    std::unordered_map<int, std::string> database;
    int serial = 100;

protected:
    Product* createProduct(const std::string& owner) override;

    void registerProduct(Product* product) override;

public:
    const std::unordered_map<int, std::string>& getDatabase();
};
