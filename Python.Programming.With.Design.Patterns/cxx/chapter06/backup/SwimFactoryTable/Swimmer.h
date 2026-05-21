#pragma once

#include <string>
#include <sstream>

class Swimmer {
public:
    std::string frname;
    std::string lname;
    int age;
    std::string club;
    std::string seedtime;
    double time;
    int lane;
    int heat;

    Swimmer(const std::string& dataline) {
        std::istringstream iss(dataline);
        std::string token;
        std::string sarray[6];
        int index = 0;
        
        while (iss >> token && index < 6) {
            sarray[index++] = token;
        }
        
        if (index >= 6) {
            frname = sarray[1];
            lname = sarray[2];
            age = std::stoi(sarray[3]);
            club = sarray[4];
            seedtime = sarray[5];
            time = 0.0;
            lane = 0;
            heat = 0;
            
            // 处理包含冒号的时间（1分钟以上）
            size_t colonPos = seedtime.find(':');
            if (colonPos != std::string::npos) {
                std::string mins = seedtime.substr(0, colonPos);
                std::string secs = seedtime.substr(colonPos + 1);
                std::string atime = mins + secs;
                time = std::stod(atime);
            } else {
                time = std::stod(seedtime);
            }
        }
    }
    
    std::string getName() const {
        return frname + " " + lname;
    }
};

