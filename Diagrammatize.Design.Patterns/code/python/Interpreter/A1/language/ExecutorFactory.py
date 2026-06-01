
from abc import ABC, abstractmethod

class ExecutorFactory(ABC):
    @abstractmethod
    def createExecutor(self, name):
        pass
