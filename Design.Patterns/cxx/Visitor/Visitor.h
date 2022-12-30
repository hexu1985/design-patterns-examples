//Visitor.h
#ifndef _VISITOR_H_
#define _VISITOR_H_

class ConcreteElementA;
class ConcreteElementB;
class Element;

class Visitor
{
public:
    virtual ~Visitor();
    virtual void Visit(ConcreteElementA* elm) = 0;
    virtual void Visit(ConcreteElementB* elm) = 0;

protected:
    Visitor();

private:
};

class ConcreteVisitorA:public Visitor
{
public:
    ConcreteVisitorA();
    virtual ~ConcreteVisitorA();
    virtual void Visit(ConcreteElementA* elm);
    virtual void Visit(ConcreteElementB* elm);

protected:
private:
};

class ConcreteVisitorB:public Visitor
{
public:
    ConcreteVisitorB();
    virtual ~ConcreteVisitorB();
    virtual void Visit(ConcreteElementA* elm);
    virtual void Visit(ConcreteElementB* elm);

protected:
private:
};

#endif //~_VISITOR_H_ 
