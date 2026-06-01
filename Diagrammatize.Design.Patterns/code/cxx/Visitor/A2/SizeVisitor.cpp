#include "SizeVisitor.hpp"

SizeVisitor::SizeVisitor() {
}

SizeVisitor::~SizeVisitor() {
}

void SizeVisitor::visit(File* file) {
    size += file->getSize();
}

void SizeVisitor::visit(Directory* directory) {
    for (auto entry : *directory) {
        entry->accept(this);
    }
}

int SizeVisitor::getSize() {
    return size;
}
