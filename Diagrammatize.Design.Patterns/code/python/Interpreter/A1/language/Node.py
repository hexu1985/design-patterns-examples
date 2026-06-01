from abc import ABC, abstractmethod
from .Executor import Executor

class Node(Executor):
    @abstractmethod
    def parse(self, context):
        pass

