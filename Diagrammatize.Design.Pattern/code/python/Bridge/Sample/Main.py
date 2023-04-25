from Display import Display
from CountDisplay import CountDisplay
from StringDisplayImpl import StringDisplayImpl

def main():
    d1 = Display(StringDisplayImpl("Hello, China."))
    d2 = CountDisplay(StringDisplayImpl("Hello, World."))
    d3 = CountDisplay(StringDisplayImpl("Hello, Universe."))
    d1.display()
    d2.display()
    d3.display()
    d3.multiDisplay(5)

if __name__ == "__main__":
    main()
