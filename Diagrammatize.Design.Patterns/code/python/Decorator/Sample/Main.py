from StringDisplay import StringDisplay
from SideBorder import SideBorder
from FullBorder import FullBorder

def main():
    b1 = StringDisplay("Hello, world.")
    b2 = SideBorder(b1, '#')
    b3 = FullBorder(b2)
    b1.show();
    b2.show();
    b3.show();
    b4 = SideBorder(
            FullBorder(
                FullBorder(
                    SideBorder(
                        FullBorder(
                            StringDisplay("hello, world.")
                        ),
                        '*'
                    )
                )
            ),
            '/'
        )
    b4.show()

if __name__ == "__main__":
    main()
