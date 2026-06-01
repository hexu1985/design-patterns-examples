import abc

class Builder(abc.ABC):
    @abc.abstractmethod
    def makeTitle(self, title):
        pass

    @abc.abstractmethod
    def makeString(self, str_):
        pass

    @abc.abstractmethod
    def makeItems(self, items):
        pass

    @abc.abstractmethod
    def close(self):
        pass

