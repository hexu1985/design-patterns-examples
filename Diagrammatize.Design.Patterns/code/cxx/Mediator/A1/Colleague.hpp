#pragma once

class Mediator;

class Colleague {
public:
    virtual ~Colleague();
    virtual void setMediator(Mediator* mediator) = 0;
    virtual void setColleagueEnabled(bool enabled) = 0;
};

