#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "Random.hpp"
#include "Memento.hpp"

class Gamer {
private:
    int money;                          // 所持金钱
    std::vector<std::string> fruits;    // 获得的水果
    Random random;                      // 随机数生成器
    static std::vector<std::string> fruitsname;      // 表示水果种类的数组

public:
    Gamer(int money);

    int getMoney();

    void bet();

    Memento* createMemento();

    void restoreMemento(Memento* memento);

    std::string toString() const;

    std::string getFruit();
};

inline
std::ostream& operator<<(std::ostream& os, const Gamer& gamer) {
    os << gamer.toString();
    return os;
}
