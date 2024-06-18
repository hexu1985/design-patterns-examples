import abc

class Drawable(abc.ABC):
    @abc.abstractmethod
    def init(self):
        pass

    @abc.abstractmethod
    def draw(self, x, y):
        pass

    @abc.abstractmethod
    def setColor(self, color):
        pass

