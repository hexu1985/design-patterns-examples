from MultiStringDisplay import MultiStringDisplay
from SideBorder import SideBorder
from FullBorder import FullBorder

def main():
    md = MultiStringDisplay()
    md.add("Good morning.")
    md.add("Good afternoon.")
    md.add("Good night, see you tomorrow.")
    md.show()

    d1 = SideBorder(md, '#')
    d1.show()

    d2 = FullBorder(md)
    d2.show()

if __name__ == "__main__":
    main()
