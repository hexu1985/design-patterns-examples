#pragma once

#include "HotDrink.hpp"
#include <memory>

struct HotDrinkFactory { // abstract factory
    virtual std::unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory {
    std::unique_ptr<HotDrink> make() const override { return std::make_unique<Tea>(); }
};

struct CoffeeFactory : HotDrinkFactory {
    std::unique_ptr<HotDrink> make() const override { return std::make_unique<Coffee>(); }
};
