#pragma once

#include "StraightSeeding.h"

class CircleSeeding : public StraightSeeding {
public:
    CircleSeeding(const std::vector<Swimmer>& sw, int nlanes) 
        : StraightSeeding(sw, nlanes) {}
    
    void seed() override {
        StraightSeeding::seed();
        
        int circle = 0;
        if (numHeats >= 2) {
            if (numHeats >= 3) {
                circle = 3;
            } else {
                circle = 2;
            }
        }
        
        int i = 0;
        for (int j = 0; j < numLanes; j++) {
            for (int k = 0; k < circle; k++) {
                if (i < count) {
                    swimmers[i].lane = lanes[j];
                    swimmers[i].heat = numHeats - k;
                    i++;
                }
            }
        }
    }
};

