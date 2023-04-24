#include "CountDisplay.hpp"
#include "FileDisplayImpl.hpp"

int main() {
    CountDisplay* d = new CountDisplay(new FileDisplayImpl("star.txt"));
    d->multiDisplay(3);

    return 0;
}
