
import time
import traceback
import sys
import pickle

from game.Memento import Memento
from game.Gamer import Gamer

SAVEFILENAME = "game.dat"

def saveMemento(memento):
    try:
        out = open(SAVEFILENAME, 'wb')
        out.write(pickle.dumps(memento))
    except OSError as e:
        traceback.print_exc(limit=1, file=sys.stdout)

def loadMemento():
    memento = None
    try:
        infile = open(SAVEFILENAME, 'rb')
        memento = pickle.loads(infile.read())
    except OSError as e:
        traceback.print_exc(limit=1, file=sys.stdout)

    return memento

def main():
    gamer = Gamer(100)
    memento = loadMemento()
    if memento:
        print("读取上次保存存档开始游戏。")
        gamer.restoreMemento(memento)
    else:
        print("新游戏。")
        memento = gamer.createMemento()

    for i in range(100):
        print("==== {}".format(i))
        print("当前状态:{}".format(gamer))

        gamer.bet()

        print("所持金钱为{}元。".format(gamer.getMoney()))

        if gamer.getMoney() > memento.getMoney():
            print("    （所持金钱增加了许多，因此保存游戏当前的状态）")
            memento = gamer.createMemento();
            saveMemento(memento)
        elif gamer.getMoney() < memento.getMoney() // 2:
            print("    （所持金钱减少了许多，因此将游戏恢复至以前的状态）")
            gamer.restoreMemento(memento)

        time.sleep(1)
        print("")


if __name__ == "__main__":
    main()

