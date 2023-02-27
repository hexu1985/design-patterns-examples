from framework.Factory import Factory
from .IDCard import IDCard

class IDCardFactory(Factory):
    def __init__(self):
        self.owners = list()

    def createProduct(self, owner):
        return IDCard(owner)

    def registerProduct(self, product):
        self.owners.append(product.getOwner())

    def getOwners(self):
        return self.owners
