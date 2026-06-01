#include "Memento.hpp"
#include "json.hpp"

using Json = nlohmann::json;

void to_json(Json& j, const Memento& m) {
    j = Json{{"money", m.getMoney()}, {"fruits", m.getFruits()}};
}

void from_json(const Json& j, Memento& m) {
    int money;
    std::vector<std::string> fruits;

    j.at("money").get_to(money);
    j.at("fruits").get_to(fruits);
    set_memento(m, money, fruits);
}

void set_memento(Memento& m, int money, const std::vector<std::string>& fruits) {
    m.money = money;
    m.fruits = fruits;
}

int Memento::getMoney() const {
    return money;
}

Memento::Memento(int money_): money(money_) {
}

void Memento::addFruit(const std::string& fruit) {
    fruits.push_back(fruit);
}

std::vector<std::string> Memento::getFruits() const {
    return fruits;
}

std::string Memento::dumpToJson() {
    Json j = *this;
    return j.dump(4);
}

Memento* Memento::createFromJson(std::string& data) {
    Json j = Json::parse(data);
    Memento* m = new Memento(0);
    *m = j;
    return m;
}
