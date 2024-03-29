import abc

class Builder(abc.ABC):
    def __init__(self):
        self.initialized = False

    def makeTitle(self, title):
        if not self.initialized:
            self.buildTitle(title)
            self.initialized = True

    def makeString(self, str_):
        if self.initialized:
            self.buildString(str_)

    def makeItems(self, items):
        if self.initialized:
            self.buildItems(items)

    def close(self):
        if self.initialized:
            self.buildDone()

    @abc.abstractmethod
    def buildTitle(self, title):
        pass

    @abc.abstractmethod
    def buildString(self, str_):
        pass

    @abc.abstractmethod
    def buildItems(self, items):
        pass

    @abc.abstractmethod
    def buildDone(self):
        pass
