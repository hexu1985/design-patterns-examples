import random
import time

from NumberGenerator import NumberGenerator

class RandomNumberGenerator(NumberGenerator):
    def __init__(self):
        super().__init__()
        self.random = random.Random()
        self.number = 0

    def getNumber(self):
        return self.number

    def execute(self):
        for i in range(0, 20):
            self.number = self.random.randint(0, 49)
            self.notifyObservers()
            time.sleep(1)
