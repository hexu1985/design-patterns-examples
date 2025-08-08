#include "Canvas.hpp"
#include <QPainter>

class Rectangle {
private:
    QPainter* painter;

public:
    Rectangle(QPainter* p): painter(p) {
    }

    void draw(int x, int y, int w, int h) {
        painter->drawRect(x, y, w, h);
    }
};

class Square : public Rectangle {
public:
    Square(QPainter* p): Rectangle(p) {
    }

    void draw(int x, int y, int w) {
        Rectangle::draw(x, y, w, w);
    }
};

Canvas::Canvas(QWidget *parent)
    : QWidget(parent)
{
    resize(400, 200);
}

void Canvas::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    Rectangle rect1(&painter);      // and a Rectangls
    rect1.draw(30, 10, 120, 80);    // draw a rectangle

    Square square(&painter);        // create a Square
    square.draw(200, 50, 60);       // and draw a square
}

Canvas::~Canvas()
{

}
