#pragma once

#include <vector>
#include <string>

class Memento {
private:
    int money;                              // 所持金钱
    std::vector<std::string> fruits;        // 当前获得的水果

public:
    int getMoney() const;
    Memento(int money=0);
    void addFruit(const std::string& fruit);
    std::vector<std::string> getFruits() const;

    std::string dumpToJson();
    static Memento* createFromJson(std::string& data);

    friend void set_memento(Memento& m, int money, const std::vector<std::string>& fruits);
};
