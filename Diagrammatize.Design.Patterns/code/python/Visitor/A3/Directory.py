
from Entry import Entry

class Directory(Entry):
    def __init__(self, name):
        self.name = name
        self.dir = []

    def getName(self):
        return self.name

    def getSize(self):
        size = 0
        for entry in self.dir:
            size += entry.getSize()

        return size

    def add(self, entry):
        self.dir.append(entry)
        return self

    def __iter__(self):
        return iter(self.dir)

    def accept(self, v):
        v.visitDirectory(self)
    
