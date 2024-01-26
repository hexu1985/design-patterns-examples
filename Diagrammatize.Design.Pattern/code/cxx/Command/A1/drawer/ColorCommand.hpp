#pragma once

#include <QColor>
#include "command/Command.hpp"
#include "Drawable.hpp"

class ColorCommand: public Command {
protected:
    Drawable* drawable;

private:
    QColor color;

public:
    ColorCommand(Drawable* drawable, QColor color);

    void execute() override;
};
