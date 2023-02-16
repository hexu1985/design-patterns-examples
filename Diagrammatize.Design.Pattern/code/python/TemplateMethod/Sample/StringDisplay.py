from AbstractDisplay import AbstractDisplay


class StringDisplay(AbstractDisplay):           # StringDisplay也是AbstractDisplay的子类 
    def __init__(self, string):                     # 构造函数中接收的字符串被
        self.string = string                        # 保存在字段中
        self.width = len(string)                    # 同时将字符串的字节长度也保存在字段中，以供后面使用 

    def open(self):                                 # 重写的open方法
        self.printLine()                            # 调用该类的printLine方法画线

    def print(self):                                # print方法
        print("|" + self.string + "|")              # 给保存在字段中的字符串前后分别加上"|"并显示出来 

    def close(self):                                # close方法
        self.printLine()                            # 与open方法一样，调用printLine方法画线

    def printLine(self):                            # 被open和close方法调用。由于可见性是private，因此只能在本类中被调用 
        print("+", end="")                          # 显示表示方框的角的"+"
        for _ in range(self.width):                 # 显示width个"-"
            print("-", end="")                      # 组成方框的边框
        print("+")                                  # /显示表示方框的角的"+"

