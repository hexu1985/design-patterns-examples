
class Hand:
    HANDVALUE_GUU = 0   # 表示石头的值
    HANDVALUE_CHO = 1   # 表示剪刀的值
    HANDVALUE_PAA = 2   # 表示布的值
    hand = None
    name = [            # 表示猜拳中手势所对应的字符串       
            "石头", "剪刀", "布",
            ]

    def __init__(self, handvalue):
        self.handvalue = handvalue  # 表示猜拳中出的手势的值

    @classmethod
    def getHand(cls, handvalue):    # 根据手势的值获取其对应的实例
        if not cls.hand:
            cls.hand = [            # 表示猜拳中3种手势的实例
                    Hand(cls.HANDVALUE_GUU), 
                    Hand(cls.HANDVALUE_CHO), 
                    Hand(cls.HANDVALUE_PAA)
                    ]
        return cls.hand[handvalue]

    def isStrongerThan(self, h):    # 如果this胜了h则返回true
        return self.fight(h) == 1

    def isWeakerThan(self, h):      # 如果this输给了h则返回true
        return self.fight(h) == -1

    def fight(self, h):             # 计分：平0, 胜1, 负-1
        if (self.handvalue == h.handvalue):
            return 0
        elif ((self.handvalue + 1) % 3 == h.handvalue): 
            return 1
        else:
            return -1

    def __str__(self):              # 转换为手势值所对应的字符串
        return self.name[self.handvalue]

