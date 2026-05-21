#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Swimmer.h"
#include "Seeding.h"

class Event {
protected:
    int numLanes;
    std::vector<Swimmer> swimmers;

public:
    Event(const std::string& filename, int lanes) : numLanes(lanes) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        
        std::string line;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                Swimmer sw(line);
                swimmers.push_back(sw);
            }
        }
        file.close();
    }
    
    virtual ~Event() {}
    
    virtual Seeding* getSeeding() = 0;
    virtual bool isPrelim() const = 0;
    virtual bool isFinal() const = 0;
    virtual bool isTimedFinal() const = 0;
};

