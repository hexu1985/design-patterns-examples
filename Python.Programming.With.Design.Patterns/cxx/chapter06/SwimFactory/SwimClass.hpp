#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// -------------------------- Swimmer 类 --------------------------
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
        std::vector<std::string> sarray;
        std::string line = dataline;
        size_t pos = 0;
        while ((pos = line.find(' ')) != std::string::npos) {
            sarray.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        sarray.push_back(line);

        frname = sarray[1];
        lname = sarray[2];
        age = std::stoi(sarray[3]);
        club = sarray[4];
        seedtime = sarray[5];
        lane = 0;
        heat = 0;

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

    std::string getName() const {
        return frname + " " + lname;
    }
};

// -------------------------- Seeding 抽象基类 --------------------------
class Seeding {
public:
    virtual std::vector<Swimmer*> getSwimmers() = 0;
    virtual ~Seeding() = default;
};

// -------------------------- Event 抽象基类 --------------------------
class Event {
public:
    int numLanes;
    std::vector<Swimmer*> swimmers;

    Event(const std::string& filename, int lanes) : numLanes(lanes) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                swimmers.push_back(new Swimmer(line));
            }
        }
        file.close();
    }

    virtual ~Event() {
        for (Swimmer* s : swimmers) delete s;
    }

    virtual Seeding* getSeeding() = 0;
    virtual bool isPrelim() = 0;
    virtual bool isFinal() = 0;
    virtual bool isTimedFinal() = 0;
};

// -------------------------- PrelimEvent --------------------------
class PrelimEvent : public Event {
public:
    PrelimEvent(const std::string& filename, int lanes) : Event(filename, lanes) {}

    Seeding* getSeeding() override {
        return new CircleSeeding(swimmers, numLanes);
    }

    bool isPrelim() override { return true; }
    bool isFinal() override { return false; }
    bool isTimedFinal() override { return false; }
};

// -------------------------- TimedFinalEvent --------------------------
class TimedFinalEvent : public Event {
public:
    TimedFinalEvent(const std::string& filename, int lanes) : Event(filename, lanes) {}

    Seeding* getSeeding() override {
        return new StraightSeeding(swimmers, numLanes);
    }

    bool isPrelim() override { return false; }
    bool isFinal() override { return false; }
    bool isTimedFinal() override { return true; }
};

// -------------------------- StraightSeeding --------------------------
class StraightSeeding : public Seeding {
protected:
    std::vector<Swimmer*> swimmers;
    int numLanes;
    int count;
    std::vector<int> lanes;
    int lastHeat;
    int numHeats;

public:
    StraightSeeding(std::vector<Swimmer*>& sw, int nlanes)
        : swimmers(sw), numLanes(nlanes), count(sw.size()) {
        lanes = calcLaneOrder();
        seed();
    }

    virtual ~StraightSeeding() = default;

    std::vector<Swimmer*> sortUpwards() {
        std::vector<Swimmer*> swmrs = swimmers;
        for (int i = 0; i < count; i++) {
            for (int j = i; j < count; j++) {
                if (swmrs[i]->time > swmrs[j]->time) {
                    std::swap(swmrs[i], swmrs[j]);
                }
            }
        }
        return swmrs;
    }

    std::vector<int> calcLaneOrder() {
        std::vector<int> lanesVec;
        double mid = numLanes / 2.0;
        int ln;
        if (odd(numLanes)) {
            ln = static_cast<int>(mid) + 1;
        } else {
            ln = static_cast<int>(mid);
        }

        int incr = 1;
        for (int i = 0; i < numLanes; i++) {
            lanesVec.push_back(ln);
            ln = static_cast<int>(mid) + incr;
            incr = -incr;
            if (incr > 0) incr++;
        }
        return lanesVec;
    }

    bool odd(int num) const {
        return (num % 2) != 0;
    }

    virtual void seed() {
        std::vector<Swimmer*> asw = sortUpwards();
        lastHeat = count % numLanes;
        if (lastHeat < 3) lastHeat = 3;

        int lastLanes = count - lastHeat;
        numHeats = count / numLanes;
        if (lastLanes > 0) numHeats++;
        int heats = numHeats;

        int j = 0;
        for (int i = 0; i < lastLanes; i++) {
            Swimmer* sw = asw[i];
            sw->lane = lanes[j];
            j++;
            sw->heat = heats;
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
            Swimmer* sw = asw[i];
            sw->lane = lanes[j];
            j++;
            sw->heat = heats;
        }

        swimmers.clear();
        for (int i = 0; i < count; i++) {
            swimmers.push_back(asw[i]);
        }
    }

    std::vector<Swimmer*> getSwimmers() override {
        return swimmers;
    }
};

// -------------------------- CircleSeeding --------------------------
class CircleSeeding : public StraightSeeding {
public:
    CircleSeeding(std::vector<Swimmer*>& sw, int nlanes) : StraightSeeding(sw, nlanes) {}

    void seed() override {
        StraightSeeding::seed();
        int circle = 0;
        if (numHeats >= 2) {
            if (numHeats >= 3) circle = 3;
            else circle = 2;
        }

        int i = 0;
        for (int j = 0; j < numLanes; j++) {
            for (int k = 0; k < circle; k++) {
                if (i < count) {
                    swimmers[i]->lane = lanes[j];
                    swimmers[i]->heat = numHeats - k;
                    i++;
                }
            }
        }
    }
};

