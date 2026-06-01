
import time

from game import Memento, Gamer

def main():
    gamer = Gamer(100)
    memento = gamer.createMemento()
    for i in range(100):
        print("==== {}".format(i))
        print("当前状态:{}".format(gamer))

        gamer.bet()

        print("所持金钱为{}元。".format(gamer.getMoney()))

        if gamer.getMoney() > memento.getMoney():
            print("    （所持金钱增加了许多，因此保存游戏当前的状态）")
            memento = gamer.createMemento();
        elif gamer.getMoney() < memento.getMoney() // 2:
            print("    （所持金钱减少了许多，因此将游戏恢复至以前的状态）")
            gamer.restoreMemento(memento)

        time.sleep(1)
        print("")


if __name__ == "__main__":
    main()
