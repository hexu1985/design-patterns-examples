#include "WinningStrategy.hpp"

WinningStrategy::WinningStrategy(int seed): random(seed) {
}

Hand WinningStrategy::nextHand() {
    if (!won) {
        prevHand = Hand::getHand(random.randomInt(0, 2));
    }
    return prevHand;
}

void WinningStrategy::study(bool win) {
    won = win;
}
