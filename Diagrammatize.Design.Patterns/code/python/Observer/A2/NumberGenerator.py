import abc

class NumberGenerator(abc.ABC):
    def __init__(self):
        self.observers = list()

    def addObserver(self, observer):
        self.observers.append(observer)

    def deleteObserver(self, observer):
        self.observers.remove(observer)

    def notifyObservers(self):
        for o in self.observers:
            o.update(self)

    @abc.abstractmethod
    def getNumber(self):
        pass

    @abc.abstractmethod
    def execute(self):
        pass

