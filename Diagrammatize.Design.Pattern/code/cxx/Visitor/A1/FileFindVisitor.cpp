#include "FileFindVisitor.hpp"
#include "string_algorithm.hpp"

FileFindVisitor::FileFindVisitor(const std::string& filetype_) : filetype(filetype_) {
}

FileFindVisitor::~FileFindVisitor() {
}

void FileFindVisitor::visit(File* file) {
    if (ends_with(file->getName(), filetype)) {
        found.push_back(file);
    }
}

void FileFindVisitor::visit(Directory* directory) {
    for (auto entry : *directory) {
        entry->accept(this);
    }
}


const std::vector<File*>& FileFindVisitor::getFoundFiles() {
    return found;
}
