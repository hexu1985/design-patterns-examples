import copy
from framework import Product

class MessageBox(Product):
    def __init__(self, decochar):
        self.decochar = decochar

    def use(self, s):
        length = len(s)
        for i in range(length + 4):
            print(self.decochar, end="")
        print("")
        print(self.decochar + " " + s + " " + self.decochar)
        for i in range(length + 4):
            print(self.decochar, end="")
        print("")

    def createClone(self):
        return copy.deepcopy(self)

if __name__ == "__main__":
    a = MessageBox("*")
    b = a.createClone()
    b.use("abc")
