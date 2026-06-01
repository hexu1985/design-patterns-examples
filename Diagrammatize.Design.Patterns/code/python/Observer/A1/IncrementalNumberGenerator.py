from NumberGenerator import NumberGenerator

class IncrementalNumberGenerator(NumberGenerator):
    def __init__(self, start, end, inc):
        super().__init__()
        self.number = start
        self.end = end
        self.inc = inc

    def getNumber(self):
        return self.number

    def execute(self):
        while self.number < self.end:
            self.notifyObservers()
            self.number += self.inc
