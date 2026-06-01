from DisplayImpl import DisplayImpl

class CharDisplayImpl(DisplayImpl):
    def __init__(self, head, body, foot):
        self.head = head
        self.body = body
        self.foot = foot

    def rawOpen(self):
        print(self.head, end="")

    def rawPrint(self):
        print(self.body, end="")

    def rawClose(self):
        print(self.foot)
