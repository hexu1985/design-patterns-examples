import abc
import collections

class Entry(abc.ABC):
    def __init__(self):
        self.parent = None

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

    def getFullName(self):
        fullname = collections.deque()
        entry = self
        fullname.appendleft(entry.getName())
        entry = entry.parent
        while entry is not None:
            fullname.appendleft(entry.getName())
            entry = entry.parent
        return "/"+"/".join(fullname)
