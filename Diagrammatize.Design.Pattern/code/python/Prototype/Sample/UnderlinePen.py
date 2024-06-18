import copy
from framework import Product

class UnderlinePen(Product):
    def __init__(self, ulchar):
        self.ulchar = ulchar

    def use(self, s):
        length = len(s)
        print("\""  + s + "\"")
        print(" ", end="")
        for i in range(length):
            print(self.ulchar, end="")
        print("")

    def createClone(self):
        return copy.deepcopy(self)
