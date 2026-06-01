from factory import *
import listfactory
import tablefactory

import sys

def main():
    if len(sys.argv) != 2:
        print("Usage: python {} class.name.of.ConcreteFactory".format(sys.argv[0]))
        print("Example 1: python {} ListFactory".format(sys.argv[0]))
        print("Example 2: python {} TableFactory".format(sys.argv[0]))
        sys.exit(1)

    factory = Factory.getFactory(sys.argv[1])

    page = factory.createYahooPage()
    page.output()

if __name__ == "__main__":
    main()
