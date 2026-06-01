
from Visitor import Visitor

class SizeVisitor(Visitor):
    def __init__(self):
        self.size = 0

    def getSize(self):
        return self.size

    def visitFile(self, file_):
        self.size += file_.getSize()

    def visitDirectory(self, directory):
        for entry in directory:
            entry.accept(self)
