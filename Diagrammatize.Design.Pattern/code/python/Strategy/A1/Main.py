import sys

from Player import Player
from RandomStrategy import RandomStrategy
from ProbStrategy import ProbStrategy

def main():
    if len(sys.argv) != 3:
        print("Usage: python Main.py randomseed1 randomseed2")
        print("Example: python Main.py 314 15")
        sys.exit(0)

    seed1 = int(sys.argv[1])
    seed2 = int(sys.argv[2])
    player1 = Player("Taro", ProbStrategy(seed1))
    player2 = Player("Hana", RandomStrategy(seed2))
    for i in range(10000):
        nextHand1 = player1.nextHand()
        nextHand2 = player2.nextHand()
        if (nextHand1.isStrongerThan(nextHand2)): 
            print("Winner:{}".format(player1))
            player1.win()
            player2.lose()
        elif (nextHand2.isStrongerThan(nextHand1)):
            print("Winner:{}".format(player2))
            player1.lose()
            player2.win()
        else: 
            print("Even...")
            player1.even()
            player2.even()
    print("Total result:")
    print(player1)
    print(player2)

if __name__ == "__main__":
    main()
