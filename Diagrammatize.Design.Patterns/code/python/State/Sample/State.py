import abc

class State(abc.ABC):
    @abc.abstractmethod
    def doClock(self, context, hour):
        pass

    @abc.abstractmethod
    def doUse(self, context):
        pass

    @abc.abstractmethod
    def doAlarm(self, context):
        pass

    @abc.abstractmethod
    def doPhone(self, context):
        pass


