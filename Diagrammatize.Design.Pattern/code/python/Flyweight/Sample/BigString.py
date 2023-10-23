
from BigCharFactory import BigCharFactory

class BigString:

    def __init__(self, string):
        bigchars = [None]*len(string)
        factory = BigCharFactory.getInstance()
        for i in range(len(string)):
            bigchars[i] = factory.getBigChar(string[i])
        self.bigchars = bigchars

    def print(self):
        for i in range(len(self.bigchars)):
            self.bigchars[i].print()
