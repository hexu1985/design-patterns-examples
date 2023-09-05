#include "Memento.hpp"

int Memento::getMoney() {
    return money;
}

Memento::Memento(int money_): money(money_) {
}

void Memento::addFruit(const std::string& fruit) {
    fruits.push_back(fruit);
}

std::vector<std::string> Memento::getFruits() {
    return fruits;
}
