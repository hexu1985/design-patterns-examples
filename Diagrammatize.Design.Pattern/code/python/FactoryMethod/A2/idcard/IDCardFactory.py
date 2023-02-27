from framework.Factory import Factory
from .IDCard import IDCard

class IDCardFactory(Factory):
    def __init__(self):
        self.database = dict()
        self.serial = 100

    def createProduct(self, owner):
        card = IDCard(owner, self.serial)
        self.serial += 1
        return card

    def registerProduct(self, product):
        card = product
        self.database[card.getSerial()] = card.getOwner()

    def getDatabase(self):
        return self.database
