#include "RandomStrategy.hpp"

RandomStrategy::RandomStrategy(int seed): random(seed) {
}

Hand RandomStrategy::nextHand() {
    return Hand::getHand(random.randomInt(0, 2));
}

void RandomStrategy::study(bool win) {
}
