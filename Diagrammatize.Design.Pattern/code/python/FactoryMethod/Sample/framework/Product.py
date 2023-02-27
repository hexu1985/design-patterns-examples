import abc

class Product(abc.ABC):
    @abc.abstractmethod
    def use(self):
        pass

