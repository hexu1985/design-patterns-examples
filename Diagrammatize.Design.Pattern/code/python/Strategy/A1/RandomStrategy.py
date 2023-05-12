import random

from Strategy import Strategy
from Hand import Hand

class RandomStrategy(Strategy):
    def __init__(self, seed):
        self.random = random.Random(seed)

    def study(self, win):
        pass

    def nextHand(self):
        return Hand.getHand(self.random.randint(0, 2))
