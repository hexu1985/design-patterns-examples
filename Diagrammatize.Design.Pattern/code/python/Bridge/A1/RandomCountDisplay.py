import time
import random

from CountDisplay import CountDisplay

class RandomCountDisplay(CountDisplay):
    def __init__(self, impl):
        super().__init__(impl)
        random.seed(time.time())

    def randomDisplay(self, times):
        self.multiDisplay(random.randint(0, times-1))
