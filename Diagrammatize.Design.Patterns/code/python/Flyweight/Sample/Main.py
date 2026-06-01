
import sys
from BigString import BigString

def main():
    if len(sys.argv) == 1:
        print("Usage: python {} digits".format(sys.argv[0]))
        print("Example 1: python {} 1212123".format(sys.argv[0]))
        sys.exit(1)

    bs = BigString(sys.argv[1])
    bs.print()

if __name__ == "__main__":
    main()
