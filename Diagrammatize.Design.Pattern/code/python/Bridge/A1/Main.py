from RandomCountDisplay import RandomCountDisplay
from StringDisplayImpl import StringDisplayImpl

def main():
    d = RandomCountDisplay(StringDisplayImpl("Hello, China."))
    d.randomDisplay(10)

if __name__ == "__main__":
    main()
