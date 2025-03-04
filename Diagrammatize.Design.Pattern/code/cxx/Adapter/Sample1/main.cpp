#include "Print.hpp"
#include "PrintBanner.hpp"

int main() {
    Print* p = new PrintBanner("Hello");
    p->printWeak();
    p->printStrong();
}
