#pragma once

#include "Wall.h"
#include "Material.h"
#include <memory>

class WallFactory;

class SolidWall : public Wall
{
    int width;
    Material material;
protected:
    SolidWall(const Point2D start, const Point2D end,
            const int elevation,
            const int height, const int width, const Material material);

    friend class WallFactory;

public:
    static SolidWall create_main(Point2D start, Point2D end,
            int elevation, int height)
    {
        return SolidWall{start, end, elevation, height,
            375, Material::aerated_concrete};
    }

    static std::unique_ptr<SolidWall> create_partition(Point2D start,
            Point2D end,
            int elevation, int height)
    {
        return std::unique_ptr<SolidWall>(new SolidWall(start, end, elevation,
                    height, 120, Material::brick));
    }

    friend std::ostream& operator<<(std::ostream& os, const SolidWall& obj)
    {
        return os
            << static_cast<const Wall&>(obj)
            << " width: " << obj.width
            << " material: " << obj.material;
    }

};
