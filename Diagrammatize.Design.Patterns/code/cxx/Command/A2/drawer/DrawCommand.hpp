#pragma once

#include <QPoint>
#include "command/Command.hpp"
#include "Drawable.hpp"

class DrawCommand: public Command {
protected:
    Drawable* drawable;

private:
    QPoint position;

public:
    DrawCommand(Drawable* drawable, QPoint position);

    void execute() override;
};
