import abc
from .Item import Item

class Link(Item):
    def __init__(self, caption, url):
        super().__init__(caption)
        self.url = url

