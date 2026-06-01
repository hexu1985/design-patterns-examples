import time
import random

from CountDisplay import CountDisplay

class RandomCountDisplay(CountDisplay):
    def __init__(self, impl):
        super().__init__(impl)
        self.random = random.Random(time.time())

    def randomDisplay(self, times):
        self.multiDisplay(self.random.randint(0, times-1))
