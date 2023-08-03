#pragma once

class NumberGenerator;

class Observer {
public:
    virtual ~Observer();
    virtual void update(NumberGenerator* generator) = 0;
};
