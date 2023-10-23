
from BigCharFactory import BigCharFactory
from BigChar import BigChar

class BigString:
    def __init__(self, string, shared):
        if shared:
            self.initShared(string)
        else:
            self.initUnshared(string)

    def initShared(self, string):
        bigchars = [None]*len(string)
        factory = BigCharFactory.getInstance()
        for i in range(len(string)):
            bigchars[i] = factory.getBigChar(string[i])
        self.bigchars = bigchars

    def initUnshared(self, string):
        bigchars = [None]*len(string)
        for i in range(len(string)):
            bigchars[i] = BigChar(string[i])
        self.bigchars = bigchars

    def print(self):
        for i in range(len(self.bigchars)):
            self.bigchars[i].print()
