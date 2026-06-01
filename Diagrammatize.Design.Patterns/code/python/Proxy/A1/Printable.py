import abc

class Printable(abc.ABC):
    @abc.abstractmethod
    def setPrinterName(self, name):
        pass

    @abc.abstractmethod
    def getPrinterName(self):
        pass

    @abc.abstractmethod
    def print(self, string):
        pass
