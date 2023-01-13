import abc

class Element(abc.ABC):

    @abc.abstractmethod
    def accept(self, v):
        pass
