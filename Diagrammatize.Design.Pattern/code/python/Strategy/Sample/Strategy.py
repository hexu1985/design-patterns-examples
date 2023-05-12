import abc

class Strategy(abc.ABC):
    @abc.abstractmethod
    def nextHand(self):
        pass

    @abc.abstractmethod
    def study(self, win):
        pass

