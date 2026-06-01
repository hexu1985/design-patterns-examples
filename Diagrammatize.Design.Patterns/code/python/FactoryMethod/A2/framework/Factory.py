import abc

class Factory(abc.ABC):
    def create(self, owner):
        p = self.createProduct(owner)
        self.registerProduct(p)
        return p

    @abc.abstractmethod
    def createProduct(self, owner):
        pass

    @abc.abstractmethod
    def registerProduct(self, product):
        pass

