#pragma once

#include "Point2D.h"
#include <memory>

class Wall
{
    Point2D start, end;
    int elevation, height;

public:
    virtual ~Wall() = default;
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

    bool intersects(const Wall& other) const
    {
        return false;
    }

private:
    class BasicWallFactory
    {
        friend class Wall; // optional
        BasicWallFactory() = default;
    public:
        std::shared_ptr<Wall> create(const Point2D start, const Point2D end, const int elevation, const int height)
        {
            Wall* wall = new Wall(start, end, elevation, height);
            return std::shared_ptr<Wall>(wall);
            //return make_shared<Wall>(start, end, elevation, height);
        }
    };

public:
    // just a static factory
    static BasicWallFactory factory;
};
