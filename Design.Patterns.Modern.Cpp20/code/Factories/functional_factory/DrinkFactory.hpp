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

class DrinkWithVolumeFactory {
    std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;

public:
    DrinkWithVolumeFactory() {
        factories["tea"] = [] {
            auto tea = std::make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };
        factories["coffee"] = [] {
            auto coffee = std::make_unique<Coffee>();
            coffee->prepare(100);
            return coffee;
        };
    }

    std::unique_ptr<HotDrink> make_drink(const std::string &name) {
        return factories["tea"]();
    }
};
