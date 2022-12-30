//Visitor.cpp
#include "Visitor.h"
#include "Element.h"
#include <iostream>

using namespace std;

Visitor::Visitor()
{
}

Visitor::~Visitor()
{
}

ConcreteVisitorA::ConcreteVisitorA()
{
}

ConcreteVisitorA::~ConcreteVisitorA()
{
}

void ConcreteVisitorA::Visit(ConcreteElementA* elm)
{
    cout << "ConcreteVisitorA: i will visit ConcreteElementA..." << endl;
}

void ConcreteVisitorA::Visit(ConcreteElementB* elm)
{
    cout << "ConcreteVisitorA: i will visit ConcreteElementB..." << endl;
}

ConcreteVisitorB::ConcreteVisitorB()
{
}

ConcreteVisitorB::~ConcreteVisitorB()
{
}

void ConcreteVisitorB::Visit(ConcreteElementA* elm)
{
    cout << "ConcreteVisitorB: i will visit ConcreteElementA..." << endl;
}

void ConcreteVisitorB::Visit(ConcreteElementB* elm)
{
    cout << "ConcreteVisitorB: i will visit ConcreteElementB..." << endl;
}
