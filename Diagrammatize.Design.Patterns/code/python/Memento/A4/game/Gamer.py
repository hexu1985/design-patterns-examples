import time
import random

from .Memento import Memento

class Gamer:
    fruitsname = [ "苹果", "葡萄", "香蕉", "橘子", ]

    def __init__(self, money):
        self.money = money
        self.fruits = list()
        self.random = random.Random(time.time())

    def getMoney(self):
        return self.money

    def bet(self):
        dice = self.random.randint(1, 6)
        if dice == 1:
            self.money += 100
            print("所持金钱增加了。")
        elif dice == 2:
            self.money //= 2
            print("所持金钱减半了。")
        elif dice == 6:
            f = self.getFruit()
            print("获得了水果({})。".format(f));
            self.fruits.append(f)
        else:
            print("什么都没有发生。")

    def createMemento(self):
        m = Memento(self.money)
        for f in self.fruits:
            if f.startswith("好吃的"):
                m.addFruit(f)

        return m

    def restoreMemento(self, memento):
        self.money = memento.getMoney()
        self.fruits = memento.getFruits()

    def __str__(self):
        return "[money = {}, fruits = {}]".format(self.money, self.fruits)

    def getFruit(self):
        prefix = ""
        if self.random.randint(0, 1):
            prefix = "好吃的"

        return prefix + Gamer.fruitsname[self.random.randint(0, len(Gamer.fruitsname)-1)]
