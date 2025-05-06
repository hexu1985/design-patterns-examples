#pragma once

#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"
#include <functional>
#include <map>
#include <memory>

struct DrinkFactory {
    std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;

    DrinkFactory() {
        hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
        hot_factories["tea"] = std::make_unique<TeaFactory>();
    }

    std::unique_ptr<HotDrink> make_drink(const std::string &name) {
        auto drink = hot_factories[name]->make();
        drink->prepare(100);
        return drink;
    }
};

