
from Visitor import Visitor

class FileFindVisitor(Visitor):
    def __init__(self, filetype):
        self.filetype = filetype
        self.found = list()

    def getFoundFiles(self):
        return iter(self.found)

    def visitFile(self, file_):
        if file_.getName().endswith(self.filetype):
            self.found.append(file_)

    def visitDirectory(self, directory):
        for entry in directory:
            entry.accept(self)
