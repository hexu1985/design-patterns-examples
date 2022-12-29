#include "ElementArrayList.hpp"

ElementArrayList::ElementArrayList() {
}

ElementArrayList::~ElementArrayList() {
}

void ElementArrayList::accept(Visitor* v) {
    for (auto e: *this) {
        e->accept(v);
    }
}
