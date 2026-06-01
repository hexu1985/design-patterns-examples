from framework import Product

class IDCard(Product):
    def __init__(self, owner, serial):
        print("制作" + owner + "(" + str(serial) + ")" + "的ID卡。")
        self.owner = owner
        self.serial = serial

    def use(self):
        print("使用" + self.owner + "(" + str(self.serial) + ")" + "的ID卡。")

    def getOwner(self):
        return self.owner

    def getSerial(self):
        return self.serial
