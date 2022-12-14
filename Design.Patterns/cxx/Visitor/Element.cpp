//Element.cpp
#include "Element.h"
#include "Visitor.h"
#include <iostream>

using namespace std;

Element::Element()
{
} 

Element::~Element()
{
}

void Element::Accept(Visitor* vis)
{
}

ConcreteElementA::ConcreteElementA()
{
}

ConcreteElementA::~ConcreteElementA()
{
}

void ConcreteElementA::Accept(Visitor* vis)
{
    cout << "visiting ConcreteElementA..." << endl;
    vis->Visit(this);
}

ConcreteElementB::ConcreteElementB()
{
}

ConcreteElementB::~ConcreteElementB()
{
}

void ConcreteElementB::Accept(Visitor* vis)
{
    cout << "visiting ConcreteElementB..." << endl;
    vis->Visit(this);
}
