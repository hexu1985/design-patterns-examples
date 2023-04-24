#include "Display.hpp"
#include "DisplayImpl.hpp"

Display::Display(DisplayImpl* impl_): impl(impl_) {
}

Display::~Display() {
}

void Display::open() {
    impl->rawOpen();
}

void Display::print() {
    impl->rawPrint();
}

void Display::close() {
    impl->rawClose();
}

void Display::display() {
    open();
    print();                    
    close();
}
