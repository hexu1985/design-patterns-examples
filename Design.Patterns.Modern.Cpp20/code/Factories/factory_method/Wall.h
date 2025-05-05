#pragma once

#include "Point2D.h"

class Wall
{
    Point2D start, end;
    int elevation, height;

public:
    Wall(Point2D start, Point2D end, int elevation, int height)
        : start{start}, end{end}, elevation{elevation}, height
        {height} { }

    friend std::ostream& operator<<(std::ostream& os, const Wall& obj)
    {
        return os
            << "start: " << obj.start
            << " end: " << obj.end
            << " elevation: " << obj.elevation
            << " height: " << obj.height;
    }
};
