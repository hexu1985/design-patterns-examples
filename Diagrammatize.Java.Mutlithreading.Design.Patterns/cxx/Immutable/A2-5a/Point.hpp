#pragma once

#include <string>

class Point {
public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    std::string toString() const {
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }
};
