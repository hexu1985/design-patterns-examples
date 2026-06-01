from AbstractDisplay import AbstractDisplay

class CharDisplay(AbstractDisplay):     # CharDisplay是AbstractDisplay的子类 
    def __init__(self, ch):                 # 构造函数中接收的字符被
        self.ch = ch                        # 保存在字段中

    def open(self):                         # 在父类中是抽象方法，此处重写该方法  
        print("<<", end="")                 # 显示开始字符"<<"

    def print(self):                        # 同样地重写print方法。该方法会在display中被重复调用
        print(self.ch, end="")              # 显示保存在字段ch中的字符

    def close(self):                        # 同样地重写close方法
        print(">>")                         # 显示结束字符">>"
