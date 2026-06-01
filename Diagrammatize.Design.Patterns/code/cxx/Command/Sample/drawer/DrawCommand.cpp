#include "DrawCommand.hpp"

DrawCommand::DrawCommand(Drawable* drawable_, QPoint position_):
    drawable(drawable_), position(position_) {
}

void DrawCommand::execute() {
    drawable->draw(position.x(), position.y());
}
