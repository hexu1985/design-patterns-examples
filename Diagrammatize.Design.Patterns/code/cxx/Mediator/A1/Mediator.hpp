#pragma once

class Mediator {
public:
    virtual ~Mediator();

    virtual void createColleagues() = 0;
    virtual void colleagueChanged() = 0;
};
