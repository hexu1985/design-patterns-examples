#include "Hand.hpp"
#include <iostream>

Hand Hand::hand[] = {
    Hand(HANDVALUE_GUU),
    Hand(HANDVALUE_CHO),
    Hand(HANDVALUE_PAA),
};

std::string Hand::name[] = {
    "石头", "剪刀", "布",
};

Hand::Hand(int handvalue_): handvalue(handvalue_) {
}

const Hand& Hand::getHand(int handvalue) {
    return hand[handvalue];
}

bool Hand::isStrongerThan(const Hand& h) const {
    return fight(h) == 1;
}

bool Hand::isWeakerThan(const Hand& h) const {
    return fight(h) == -1;
}

std::string Hand::toString() const {
    return name[handvalue];
}

int Hand::fight(const Hand& h) const {
    if (handvalue == h.handvalue) {
        return 0;
    } else if ((handvalue + 1) % 3 == h.handvalue) {
        return 1;
    } else {
        return -1;
    }
}

std::ostream& operator<<(std::ostream& out, const Hand& hand) {
    out << hand.toString();
    return out;
}
