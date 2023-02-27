from framework.Product import Product

class IDCard(Product):
    def __init__(self, owner):
        print("制作" + owner + "的ID卡。")
        self.owner = owner

    def use(self):
        print("使用" + self.owner + "的ID卡。")

    def getOwner(self):
        return self.owner
