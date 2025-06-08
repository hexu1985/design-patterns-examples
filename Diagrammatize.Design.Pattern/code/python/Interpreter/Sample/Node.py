import abc

class Node(abc.ABC):
    @abc.abstractmethod
    def parse(self, context):
        pass

