#pragma once

#include <vector>
#include <memory>

#include "Material.h"
#include "SolidWall.h"

class WallFactory
{
    static std::vector<std::weak_ptr<Wall>> walls;
public:
    static std::shared_ptr<SolidWall> create_main(Point2D start, Point2D end, int elevation, int height)
    {
        if (elevation < 0) return {};

        return std::shared_ptr<SolidWall>(new SolidWall(start, end, elevation, height, 275, Material::aerated_concrete));
    }

    static std::shared_ptr<SolidWall> create_partition(Point2D start, Point2D end, int elevation, int height)
    {
        const auto this_wall = new SolidWall{start, end, elevation, height, 120, Material::brick};

        // ensure we don't intersect other walls
        for (const auto wall: walls)
        {
            if (auto p = wall.lock())
            {
                if (this_wall->intersects(*p))
                {
                    delete this_wall;
                    return {};
                }
            }
        }

        std::shared_ptr<SolidWall> ptr(this_wall);
        walls.push_back(ptr);
        return ptr;
    }
};
