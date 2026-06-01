from .Item import Item

class Tray(Item):
    def __init__(self, caption):
        super().__init__(caption)
        self.tray = list()

    def add(self, item):
        self.tray.append(item)
