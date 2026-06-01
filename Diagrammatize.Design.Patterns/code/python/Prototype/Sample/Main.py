from framework import Manager
from UnderlinePen import UnderlinePen
from MessageBox import MessageBox

def main():
    # 准备
    manager = Manager()
    upen = UnderlinePen('~')
    mbox = MessageBox('*')
    sbox = MessageBox('/')
    manager.register("strong message", upen)
    manager.register("warning box", mbox)
    manager.register("slash box", sbox)
    
    # 生成
    p1 = manager.create("strong message")
    p1.use("Hello, world.")
    p2 = manager.create("warning box")
    p2.use("Hello, world.")
    p3 = manager.create("slash box")
    p3.use("Hello, world.")

if __name__ == "__main__":
    main()
