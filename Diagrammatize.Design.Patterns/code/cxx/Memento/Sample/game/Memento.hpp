#pragma once

#include <vector>
#include <string>

class Memento {
private:
    int money;                              // 所持金钱
    std::vector<std::string> fruits;        // 当前获得的水果

public:
    int getMoney();
    Memento(int money);
    void addFruit(const std::string& fruit);
    std::vector<std::string> getFruits();
};
