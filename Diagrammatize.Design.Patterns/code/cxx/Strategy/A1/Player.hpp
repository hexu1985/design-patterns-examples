#pragma once

#include "Hand.hpp"
#include "Strategy.hpp"

#include <string>
#include <iosfwd>

class Player {
private:
    std::string name;
    Strategy* strategy;
    int wincount = 0;
    int losecount = 0;
    int gamecount = 0;

public:
    Player(const std::string& name, Strategy* strategy);    // 赋予姓名和策略

    Hand nextHand();    // 策略决定下一局要出的手势

    void win();         // 胜
    void lose();        // 负
    void even();        // 平
    std::string toString() const; 
};

std::ostream& operator<<(std::ostream&, const Player&);
