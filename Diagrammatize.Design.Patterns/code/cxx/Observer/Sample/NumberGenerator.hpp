#pragma once 

#include <list>

class Observer;

class NumberGenerator {
private:
    std::list<Observer*> observers;

public:
    virtual ~NumberGenerator();

    void addObserver(Observer* observer);

    void deleteObserver(Observer* observer);

    void notifyObservers();

    virtual int getNumber() = 0;
    virtual void execute() = 0;
};
