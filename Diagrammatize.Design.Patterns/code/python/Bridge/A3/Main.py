from IncreaseDisplay import IncreaseDisplay
from CharDisplayImpl import CharDisplayImpl

def main():
    d1 = IncreaseDisplay(CharDisplayImpl('<', '*', '>'), 1);
    d2 = IncreaseDisplay(CharDisplayImpl('|', '#', '-'), 2);
    d1.increaseDisplay(4);
    d2.increaseDisplay(6);

if __name__ == "__main__":
    main()
