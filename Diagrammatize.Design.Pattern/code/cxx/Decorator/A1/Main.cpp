#include "StringDisplay.hpp"
#include "SideBorder.hpp"
#include "FullBorder.hpp"
#include "UpDownBorder.hpp"

int main() {
    Display* b1 = new StringDisplay("Hello, world.");
    Display* b2 = new UpDownBorder(b1, '-');
    Display* b3 = new SideBorder(b2, '*');
    b1->show();
    b2->show();
    b3->show();
    Display* b4 = 
        new FullBorder(
                new UpDownBorder(
                    new SideBorder(
                        new UpDownBorder(
                            new SideBorder(
                                new StringDisplay("Hello, world."),
                                '*'
                                ),
                            '='
                            ),
                        '|'
                        ),
                    '/'
                    )
                );
    b4->show();
}
