from StringDisplay import StringDisplay
from SideBorder import SideBorder
from FullBorder import FullBorder
from UpDownBorder import UpDownBorder

def main():
    b1 = StringDisplay("Hello, world.")
    b2 = UpDownBorder(b1, '-')
    b3 = SideBorder(b2, '*')
    b1.show()
    b2.show()
    b3.show()
    b4 = FullBorder(
            UpDownBorder(
                SideBorder(
                    UpDownBorder(
                        SideBorder(
                            StringDisplay("Hello, world."),
                            '*'
                        ),
                        '='
                    ),
                    '|'
                ),
                '/'
            )
        )
    b4.show()

if __name__ == "__main__":
    main()
