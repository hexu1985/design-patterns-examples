from CountDisplay import CountDisplay
from FileDisplayImpl import FileDisplayImpl

def main():
    d = CountDisplay(FileDisplayImpl("star.txt"))
    d.multiDisplay(3)

if __name__ == "__main__":
    main()
