#pragma once

#include <QColor>

class Drawable {
public:
    virtual ~Drawable();
    virtual void init() = 0;
    virtual void draw(int x, int y) = 0;
    virtual void setColor(QColor color) = 0;
};
