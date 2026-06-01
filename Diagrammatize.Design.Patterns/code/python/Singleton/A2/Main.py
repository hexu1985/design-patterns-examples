
from Triple import Triple

def main():
    print("Start.")
    for i in range(9):
        triple = Triple.getInstance(i % 3)
        print("{}:{}".format(i, triple))
    print("End.")


if __name__ == "__main__":
    main()
