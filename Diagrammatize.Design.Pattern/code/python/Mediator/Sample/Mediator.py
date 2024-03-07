import abc

class Mediator(abc.ABC):
    @abc.abstractmethod
    def createColleagues(self):
        pass

    @abc.abstractmethod
    def colleagueChanged(self):
        pass
