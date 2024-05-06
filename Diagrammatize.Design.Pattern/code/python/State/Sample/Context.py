import abc

class Context(abc.ABC):
    @abc.abstractmethod
    def setClock(self, hour):
        pass

    @abc.abstractmethod
    def changeState(self, state):
        pass

    @abc.abstractmethod
    def callSecurityCenter(self, msg):
        pass

    @abc.abstractmethod
    def recordLog(self, msg):
        pass



