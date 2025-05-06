#include "DrinkFactory.hpp"
#include "HotDrink.hpp"
#include <memory>

std::unique_ptr<HotDrink> make_drink(std::string type) {
    std::unique_ptr<HotDrink> drink;
    if (type == "tea") {
        drink = std::make_unique<Tea>();
        drink->prepare(200);
    } else {
        drink = std::make_unique<Coffee>();
        drink->prepare(150);
    }

    return drink;
};

using namespace std;

int main() {
    auto d = make_drink("tea");

    DrinkFactory df;
    df.make_drink("coffee");

    return 0;
}
