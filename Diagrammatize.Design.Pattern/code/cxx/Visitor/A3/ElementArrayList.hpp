#pragma once

#include "Element.hpp"
#include <vector>

class ElementArrayList : public Element, public std::vector<Element*> {
public:
    ElementArrayList(); 
    ~ElementArrayList() override; 

    void accept(Visitor* v) override;
};
