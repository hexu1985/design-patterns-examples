
from TicketMaker import TicketMaker

def main():
    print("Start.")
    for i in range(10):
        print("{}:{}".format(i, TicketMaker.getInstance().getNextTicketNumber()))
    print("End.")


if __name__ == "__main__":
    main()
