from CharDisplay import CharDisplay
from StringDisplay import StringDisplay

def main():
    d1 = CharDisplay('H')                    # 生成一个持有'H'的CharDisplay类的实例 
    d2 = StringDisplay("Hello, world.")      # 生成一个持有"Hello, world."的StringDisplay类的实例 
    d3 = StringDisplay("See you tomorrow.")  # 生成一个持有"See you tomorrow."的StringDisplay类的实例 
    d1.display()                             # 由于d1、d2和d3都是AbstractDisplay类的子类
    d2.display()                             # 可以调用继承的display方法
    d3.display()                             # 实际的程序行为取决于CharDisplay类和StringDisplay类的具体实现 

if __name__ == "__main__":
    main()
