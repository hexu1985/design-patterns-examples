#pragma once 

#include <string>

class State;

class Context {
public:
    virtual ~Context();
    virtual void setClock(int hour) = 0;
    virtual void changeState(State* state) = 0;
    virtual void callSecurityCenter(const std::string& msg) = 0;
    virtual void recordLog(const std::string& msg) = 0;
};
