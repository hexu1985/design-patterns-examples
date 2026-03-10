#pragma once

#include "Event.h"
#include "CircleSeeding.h"

class PrelimEvent : public Event {
public:
    PrelimEvent(const std::string& filename, int lanes) 
        : Event(filename, lanes) {}
    
    Seeding* getSeeding() override {
        return new CircleSeeding(swimmers, numLanes);
    }
    
    bool isPrelim() const override { return true; }
    bool isFinal() const override { return false; }
    bool isTimedFinal() const override { return false; }
};

