#pragma once

#include "Event.h"
#include "StraightSeeding.h"

class TimedFinalEvent : public Event {
public:
    TimedFinalEvent(const std::string& filename, int lanes) 
        : Event(filename, lanes) {}
    
    Seeding* getSeeding() override {
        return new StraightSeeding(swimmers, numLanes);
    }
    
    bool isPrelim() const override { return false; }
    bool isFinal() const override { return false; }
    bool isTimedFinal() const override { return true; }
};
