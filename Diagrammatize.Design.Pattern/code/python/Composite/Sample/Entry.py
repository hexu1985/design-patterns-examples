import abc

class Entry(abc.ABC):
    @abc.abstractmethod
    def getName(self):
        pass

    @abc.abstractmethod
    def getSize(self):
        pass

    def printList(self):
        self.printListAux("")

    @abc.abstractmethod
    def printListAux(self, prefix):
        pass

    def __str__(self):
        return self.getName() + " (" + str(self.getSize()) + ")"

