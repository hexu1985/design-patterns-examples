#include <QtGui>
#include "DrawCanvas.hpp"
#include "ColorCommand.hpp"
#include <iostream>

DrawCanvas::DrawCanvas(int width, int height, std::shared_ptr<MacroCommand> history_):
    history(history_)
{
    setAutoFillBackground(true);
	
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    setPalette(palette);
    
    pix = new QPixmap(size());
    pix->fill(Qt::white);
    
    setFixedSize(width, height);
    init();
}

DrawCanvas::~DrawCanvas()	
{
    delete pix;
}

void DrawCanvas::init() 
{
    color = Qt::red;
    radius = 6;
    history->append(std::shared_ptr<Command>(new ColorCommand(this, color)));
}

void DrawCanvas::repaint()
{
    clear();
    history->execute();
    update();
}

void DrawCanvas::draw(int x, int y)
{
    QPen pen;
    pen.setColor(color);

    QPainter painter;
    painter.begin(pix);
    painter.setBrush(color);
    painter.setPen(pen);
    
    QRectF rect(x - radius, y - radius, radius * 2, radius * 2);
    painter.drawEllipse(rect);
    painter.end();
    update();
}

void DrawCanvas::setColor(QColor color_)
{
    color = color_;
}

void DrawCanvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix);
}

void DrawCanvas::clear()
{
    QPixmap *clearPix = new QPixmap(size());
    clearPix->fill(Qt::white);
    delete pix;
    pix = clearPix;
    update();
}
