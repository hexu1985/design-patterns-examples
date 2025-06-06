#pragma once

#include <iostream>

struct HotDrink {
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink {
    void prepare(int volume) override {
        std::cout << "Take tea bag, boil water, pour " << volume
            << "ml, add some lemon\n";
    }
};

struct Coffee : HotDrink {
    void prepare(int volume) override {
        std::cout << "Grind some beans, boild water, pour " << volume
            << "ml, add cream, and enjoy!\n";
    }
};
