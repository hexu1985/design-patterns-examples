#pragma once

#include <QWidget>
#include <memory>
#include "command/Command.hpp"
#include "command/MacroCommand.hpp"
#include "Drawable.hpp"

class QPoint;
class QPixmap;
class QColor;

class DrawCanvas : public QWidget, public Drawable
{
    Q_OBJECT
public:
    DrawCanvas(int width, int height, std::shared_ptr<MacroCommand> history);
    ~DrawCanvas();

    void draw(int x, int y) override;
    
    void paintEvent(QPaintEvent *);

public slots:   
    void clear();
    
private:
    QPixmap *pix = nullptr;
    int radius = 6;
    QColor color = Qt::red;
    std::shared_ptr<MacroCommand> history;
};

