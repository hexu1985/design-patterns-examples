from Hand import Hand

class Player:
    def __init__(self, name, strategy):     # 赋予姓名和策略
        self.name = name
        self.strategy = strategy
        self.wincount = 0
        self.losecount = 0
        self.gamecount = 0

    def nextHand(self):                     # 策略决定下一局要出的手势
        return self.strategy.nextHand()

    def win(self):                  # 胜
        self.strategy.study(True)
        self.wincount += 1
        self.gamecount += 1

    def lose(self):                 # 负
        self.strategy.study(False)
        self.losecount += 1
        self.gamecount += 1

    def even(self):                 # 平
        self.gamecount += 1

    def __str__(self):
        return "[" + self.name + ":" + str(self.gamecount) + " games, " + str(self.wincount) + " win, " + str(self.losecount) + " lose" + "]"

