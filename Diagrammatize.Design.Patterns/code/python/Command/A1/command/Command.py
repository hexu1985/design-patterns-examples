import abc

class Command(abc.ABC):
    @abc.abstractmethod
    def execute(self):
        pass
