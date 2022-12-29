#pragma once

#include "Visitor.hpp"

class SizeVisitor : public Visitor {
private:
    int size = 0;

public:
    SizeVisitor();
    ~SizeVisitor() override;

    void visit(File* file) override;
    void visit(Directory* directory) override;

    int getSize();
};
