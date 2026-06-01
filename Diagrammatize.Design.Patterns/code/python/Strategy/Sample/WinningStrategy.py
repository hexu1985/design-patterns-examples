import random

from Strategy import Strategy
from Hand import Hand

class WinningStrategy(Strategy):
    def __init__(self, seed):
        self.random = random.Random(seed)
        self.won = False
        self.prevHand = None

    def nextHand(self):
        if (not self.won):
            self.prevHand = Hand.getHand(self.random.randint(0, 2))
        return self.prevHand

    def study(self, win):
        self.won = win

