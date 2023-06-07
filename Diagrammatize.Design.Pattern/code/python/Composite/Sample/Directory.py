from Entry import Entry

class Directory(Entry):
    def __init__(self, name):
        self.name = name
        self.directory = list()

    def getName(self):
        return self.name

    def getSize(self):
        size = 0
        for entry in self.directory:
            size += entry.getSize()
        return size

    def add(self, entry):
        self.directory.append(entry)
        return self

    def printListAux(self, prefix):
        print(prefix + "/" + str(self))
        for entry in self.directory:
            entry.printListAux(prefix + "/" + self.name)
