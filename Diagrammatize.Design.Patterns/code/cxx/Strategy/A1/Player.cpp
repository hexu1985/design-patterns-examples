#include "Player.hpp"
#include <sstream>

Player::Player(const std::string& name_, Strategy* strategy_):
    name(name_), strategy(strategy_) {
}

Hand Player::nextHand() {    // 策略决定下一局要出的手势
    return strategy->nextHand();
}

void Player::win() {         // 胜
    strategy->study(true);
    wincount++;
    gamecount++;
}

void Player::lose() {        // 负
    strategy->study(false);
    losecount++;
    gamecount++;
}

void Player::even() {        // 平
    gamecount++;
}

std::string Player::toString() const {
    std::ostringstream os;
    os << "[" << name << ":" << gamecount << " games, " 
        << wincount << " win, " << losecount << " lose" << "]";
    return os.str();
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << player.toString();
    return out;
}
