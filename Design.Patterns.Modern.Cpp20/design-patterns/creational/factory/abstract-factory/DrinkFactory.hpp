#pragma once
#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"
#include <functional>
#include <map>
#include <memory>

using namespace std;

struct DrinkFactory {
  map<string, unique_ptr<HotDrinkFactory>> hot_factories;

  DrinkFactory() {
    hot_factories["coffee"] = make_unique<CoffeeFactory>();
    hot_factories["tea"] = make_unique<TeaFactory>();
  }

  unique_ptr<HotDrink> make_drink(const string &name) {
    auto drink = hot_factories[name]->make();
    drink->prepare(100);
    return drink;
  }
};

class DrinkWithVolumeFactory {
  map<string, function<unique_ptr<HotDrink>()>> factories;

public:
  DrinkWithVolumeFactory() {
    factories["tea"] = [] {
      auto tea = make_unique<Tea>();
      tea->prepare(200);
      return tea;
    };
    factories["coffee"] = [] {
      auto coffee = make_unique<Coffee>();
      coffee->prepare(100);
      return coffee;
    };
  }

  unique_ptr<HotDrink> make_drink(const string &name) {
    return factories["tea"]();
  }
};
