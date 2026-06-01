import abc

class DisplayImpl(abc.ABC):
    @abc.abstractmethod
    def rawOpen(self):
        pass

    @abc.abstractmethod
    def rawPrint(self):
        pass

    @abc.abstractmethod
    def rawClose(self):
        pass
