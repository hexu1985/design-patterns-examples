from Entry import Entry

class File(Entry):
    def __init__(self, name, size):
        super().__init__()
        self.name = name
        self.size = size

    def getName(self):
        return self.name

    def getSize(self):
        return self.size

    def printListAux(self, prefix):
        print(prefix + "/" + str(self))

