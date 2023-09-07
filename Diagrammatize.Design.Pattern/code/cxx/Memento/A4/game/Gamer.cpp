#include "Gamer.hpp"
#include <iostream>
#include <sstream>

#include "starts_with.hpp"

std::vector<std::string> Gamer::fruitsname = {
    "苹果", "葡萄", "香蕉", "橘子",
};

Gamer::Gamer(int money_): money(money_) {
}

int Gamer::getMoney() {
    return money;
}

void Gamer::bet() {
    int dice = random.randomInt(1, 6);
    if (dice == 1) {
        money += 100;
        std::cout << "所持金钱增加了。" << std::endl;
    } else if (dice == 2) {
        money /= 2;
        std::cout << "所持金钱减半了。" << std::endl;
    } else if (dice == 6) {
        std::string f = getFruit();
        std::cout << "获得了水果(" << f << ")。" << std::endl;
        fruits.push_back(f);
    } else {
        std::cout << "什么都没有发生。" << std::endl;
    }
}

Memento* Gamer::createMemento() {
    Memento* m = new Memento(money);
    for (auto& f: fruits) {
        if (starts_with(f, "好吃的")) {
            m->addFruit(f);
        }
    }
    return m;
}

void Gamer::restoreMemento(Memento* memento) {
    money = memento->getMoney();
    fruits = memento->getFruits();
}

std::string Gamer::toString() const {
    std::ostringstream os;
    os << "[money = " << money 
        << ", fruits = [ ";
    bool first = true;
    for (auto& f: fruits) {
        if (first) {
            first = false;
        } else {
            os << ", ";
        }
        os << f;
    }
    os << " ]]";
    return os.str();
}

std::string Gamer::getFruit() {
    std::string prefix = "";
    if (random.randomInt(0, 1)) {
        prefix = "好吃的";
    }
    return prefix + fruitsname[random.randomInt(0, fruitsname.size()-1)];
}

