import abc

class Colleague(abc.ABC):
    @abc.abstractmethod
    def setMediator(self):
        pass

    @abc.abstractmethod
    def setColleagueEnabled(self, enabled):
        pass
