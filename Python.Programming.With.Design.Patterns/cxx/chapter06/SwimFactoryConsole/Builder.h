#pragma once

#include <iostream>
#include <memory>
#include "TimedFinalEvent.h"
#include "PrelimEvent.h"
#include "Seeding.h"

class Builder {
public:
    void build() {
        int dist = 1;
        while (dist > 0) {
            std::cout << "Enter 1 for 100, 5 for 500 or 0 to quit: ";
            std::cin >> dist;
            
            if (dist == 1 || dist == 5) {
                evselect(dist);
            }
        }
    }
    
    void evselect(int dist) {
        std::unique_ptr<Event> event;
        std::unique_ptr<Seeding> seeding;
        std::vector<Swimmer> swmrs;
        
        if (dist == 5) {
            event = std::make_unique<TimedFinalEvent>("500free.txt", 6);
        } else if (dist == 1) {
            event = std::make_unique<PrelimEvent>("100free.txt", 6);
        }
        
        if (event) {
            seeding.reset(event->getSeeding());
            swmrs = seeding->getSwimmers();
            
            // 打印种子选手列表
            std::cout << "\nSeeded Swimmers:" << std::endl;
            std::cout << "Heat Lane Name                Age Seed Time" << std::endl;
            std::cout << "----------------------------------------" << std::endl;
            
            for (const auto& sw : swmrs) {
                printf("%3d %3d %-20s %3d %9s\n", 
                       sw.heat, sw.lane, sw.getName().c_str(), 
                       sw.age, sw.seedtime.c_str());
            }
            std::cout << std::endl;
        }
    }
};

