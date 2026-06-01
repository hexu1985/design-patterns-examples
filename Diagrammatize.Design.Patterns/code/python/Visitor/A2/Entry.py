
import abc
from Element import Element
from FileTreatmentException import FileTreatmentException

class Entry(Element):
    @abc.abstractmethod
    def getName(self):
        pass

    @abc.abstractmethod
    def getSize(self):
        pass

    def add(self, entry):
        raise FileTreatmentException()

    def __str__(self):
        return "{} ({})".format(self.getName(), self.getSize()) 
