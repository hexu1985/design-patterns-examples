#include "RandomCountDisplay.hpp"
#include "StringDisplayImpl.hpp"

int main() {
    RandomCountDisplay* d = new RandomCountDisplay(new StringDisplayImpl("Hello, China."));
    d->randomDisplay(10);

    return 0;
}
