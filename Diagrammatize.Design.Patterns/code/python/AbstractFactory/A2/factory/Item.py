import abc

class Item:
    def __init__(self, caption):
        self.caption = caption

    @abc.abstractmethod
    def makeHTML(self):
        pass

