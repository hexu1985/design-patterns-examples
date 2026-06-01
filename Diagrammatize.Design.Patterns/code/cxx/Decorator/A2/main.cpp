#include "MultiStringDisplay.hpp"
#include "SideBorder.hpp"
#include "FullBorder.hpp"

int main() {
    MultiStringDisplay* md = new MultiStringDisplay();
    md->add("Good morning.");
    md->add("Good afternoon.");
    md->add("Good night, see you tomorrow.");
    md->show();

    Display* d1 = new SideBorder(md, '#');
    d1->show();

    Display* d2 = new FullBorder(md);
    d2->show();
}
