#pragma once

#include "Point.hpp"
#include <memory>

class Line {
private:
    std::shared_ptr<Point> startPoint;
    std::shared_ptr<Point> endPoint;

public:
    Line(int startx, int starty, int endx, int endy)
        : startPoint{std::make_shared<Point>(startx, starty)}, 
          endPoint{std::make_shared<Point>(endx, endy)} {}

    Line(std::shared_ptr<Point> startPoint, std::shared_ptr<Point> endPoint)
        : startPoint(startPoint), endPoint(endPoint) {}

    int getStartX() const { return startPoint->getX(); }
    int getStartY() const { return startPoint->getY(); }
    int getEndX() const { return endPoint->getX(); }
    int getEndY() const { return endPoint->getY(); }

    std::string toString() const {
        return "[ Line: " + startPoint->toString() + "-" + endPoint->toString() + " ]";
    }
};
