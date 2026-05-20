#pragma once

#include "Seeding.h"
#include <vector>
#include <algorithm>

class StraightSeeding : public Seeding {
protected:
    std::vector<Swimmer> swimmers;
    int numLanes;
    int count;
    std::vector<int> lanes;
    int lastHeat;
    int numHeats;

public:
    StraightSeeding(const std::vector<Swimmer>& sw, int nlanes) 
        : swimmers(sw), numLanes(nlanes) {
        count = swimmers.size();
        lanes = calcLaneOrder();
        seed();
    }
    
    virtual ~StraightSeeding() {}
    
    virtual void seed() {
        std::vector<Swimmer> asw = sortUpwards();
        lastHeat = count % numLanes;
        if (lastHeat < 3) {
            lastHeat = 3;
        }
        
        int lastLanes = count - lastHeat;
        numHeats = count / numLanes;
        
        if (lastLanes > 0) {
            numHeats += 1;
        }
        int heats = numHeats;
        
        int j = 0;
        for (int i = 0; i < lastLanes; i++) {
            Swimmer& sw = asw[i];
            sw.lane = lanes[j];
            j++;
            sw.heat = heats;
            
            if (j >= numLanes) {
                heats--;
                j = 0;
            }
        }
        
        if (j < numLanes) {
            heats--;
            j = 0;
        }
        
        for (int i = lastLanes - 1; i < count; i++) {
            Swimmer& sw = asw[i];
            sw.lane = lanes[j];
            j++;
            sw.heat = heats;
        }
        
        swimmers.clear();
        for (int i = 0; i < count; i++) {
            swimmers.push_back(asw[i]);
        }
    }
    
    std::vector<Swimmer> sortUpwards() {
        std::vector<Swimmer> swmrs = swimmers;
        
        for (int i = 0; i < count; i++) {
            for (int j = i; j < count; j++) {
                if (swmrs[i].time > swmrs[j].time) {
                    std::swap(swmrs[i], swmrs[j]);
                }
            }
        }
        return swmrs;
    }
    
    std::vector<int> calcLaneOrder() {
        std::vector<int> lanes;
        int mid = numLanes / 2;
        if (odd(numLanes)) {
            mid = mid + 1;
        }
        
        int incr = 1;
        int ln = mid;
        
        for (int i = 0; i < numLanes; i++) {
            lanes.push_back(ln);
            ln = mid + incr;
            incr = -incr;
            if (incr > 0) {
                incr = incr + 1;
            }
        }
        return lanes;
    }
    
    std::vector<Swimmer> getSwimmers() override {
        return swimmers;
    }
    
    bool odd(int num) const {
        return (num % 2) != 0;
    }
};

