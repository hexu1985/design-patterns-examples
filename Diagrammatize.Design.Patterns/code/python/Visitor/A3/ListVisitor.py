
from Visitor import Visitor

class ListVisitor(Visitor):
    def __init__(self):
        self.currentdir = ""

    def visitFile(self, file_):
        print(self.currentdir + "/" + str(file_))

    def visitDirectory(self, directory):
        print(self.currentdir + "/" + str(directory))
        savedir = self.currentdir
        self.currentdir = self.currentdir + "/" + directory.getName();
        for entry in directory:
            entry.accept(self)
        self.currentdir = savedir
