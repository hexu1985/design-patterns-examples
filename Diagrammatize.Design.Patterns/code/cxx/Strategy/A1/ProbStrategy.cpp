#include "ProbStrategy.hpp"

ProbStrategy::ProbStrategy(int seed): random(seed) {
}

Hand ProbStrategy::nextHand() {
    int bet = random.randomInt(0, getSum(currentHandValue)-1);
    int handvalue = 0;
    if (bet < history[currentHandValue][0]) {
        handvalue = 0;
    } else if (bet < history[currentHandValue][0] + history[currentHandValue][1]) {
        handvalue = 1;
    } else {
        handvalue = 2;
    }
    prevHandValue = currentHandValue;
    currentHandValue = handvalue;
    return Hand::getHand(handvalue);
}

int ProbStrategy::getSum(int hv) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += history[hv][i];
    }
    return sum;
}

void ProbStrategy::study(bool win) {
    if (win) {
        history[prevHandValue][currentHandValue]++;
    } else {
        history[prevHandValue][(currentHandValue + 1) % 3]++;
        history[prevHandValue][(currentHandValue + 2) % 3]++;
    }
}
