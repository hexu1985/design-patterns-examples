import abc

class Display(abc.ABC):
    @abc.abstractmethod
    def getColumns(self):
        pass

    @abc.abstractmethod
    def getRows(self):
        pass

    @abc.abstractmethod
    def getRowText(self, row):
        pass

    def show(self):
        for i in range(self.getRows()):
            print(self.getRowText(i))

    def getStringLen(self, string):
        return len(string.encode())
