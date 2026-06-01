#include "ColorCommand.hpp"

ColorCommand::ColorCommand(Drawable* drawable_, QColor color_):
    drawable(drawable_), color(color_)
{
}

void ColorCommand::execute()
{
    drawable->setColor(color);
}
