
from Entry import Entry
from SizeVisitor import SizeVisitor

class Directory(Entry):
    def __init__(self, name):
        self.name = name
        self.dir = []

    def getName(self):
        return self.name

    def getSize(self):
        v = SizeVisitor()
        self.accept(v)
        return v.getSize()

    def add(self, entry):
        self.dir.append(entry)
        return self

    def __iter__(self):
        return iter(self.dir)

    def accept(self, v):
        v.visitDirectory(self)
    
