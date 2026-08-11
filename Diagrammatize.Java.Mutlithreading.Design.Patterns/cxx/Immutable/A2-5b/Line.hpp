#pragma once

#include "Point.hpp"

class Line {
private:
    Point startPoint;
    Point endPoint;

public:
    // 构造函数1：使用坐标
    Line(int startx, int starty, int endx, int endy)
        : startPoint(startx, starty), endPoint(endx, endy) {}

    // 构造函数2：使用Point对象（深拷贝）
    Line(const Point& startPoint, const Point& endPoint)
        : startPoint(startPoint), endPoint(endPoint) {}

    int getStartX() const { return startPoint.getX(); }
    int getStartY() const { return startPoint.getY(); }
    int getEndX() const { return endPoint.getX(); }
    int getEndY() const { return endPoint.getY(); }

    std::string toString() const {
        return "[ Line: " + startPoint.toString() + "-" + endPoint.toString() + " ]";
    }
};

