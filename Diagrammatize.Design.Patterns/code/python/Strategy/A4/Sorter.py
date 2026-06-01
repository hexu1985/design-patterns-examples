import abc

class Sorter(abc.ABC):
    @abc.abstractmethod
    def sort(self, data):
        pass

