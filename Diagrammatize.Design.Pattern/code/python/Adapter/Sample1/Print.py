import abc

class Print(abc.ABC):
    @abc.abstractmethod
    def printWeak(self):
        pass

    @abc.abstractmethod
    def printStrong(self):
        pass
