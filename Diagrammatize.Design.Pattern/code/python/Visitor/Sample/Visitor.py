
import abc

class Visitor(abc.ABC):

    @abc.abstractmethod
    def visitFile(self, file_):
        pass

    @abc.abstractmethod
    def visitDirectory(self, directory):
        pass

