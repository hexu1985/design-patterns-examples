
class Banner:
    def __init__(self, string):
        self.string = string

    def showWithParen(self):
        print("(" + self.string + ")")

    def showWithAster(self):
        print("*" + self.string + "*")
