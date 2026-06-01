#include "Directory.hpp"
#include "Visitor.hpp"
#include "SizeVisitor.hpp"

Directory::Directory(const std::string& name_) : name(name_) {}

Directory::~Directory() {}

std::string Directory::getName() {
    return name;
}

int Directory::getSize() {
    SizeVisitor v;
    accept(&v);
    return v.getSize();
}

Entry* Directory::add(Entry* entry) {
    dir.push_back(entry);
    return this;
}

void Directory::accept(Visitor* v) {
    v->visit(this);
}
