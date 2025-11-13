#include "Canvas.hpp"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setFixedSize(300, 200);
}

void Canvas::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    // Draw existing shapes
    for (const auto& shape : shapes) {
        if (shape.type == "circle") {
            painter.setBrush(QBrush(Qt::red));
            painter.drawEllipse(130, 40, 70, 70);
        } else if (shape.type == "square") {
            painter.setBrush(QBrush(Qt::blue));
            painter.drawRect(10, 80, 100, 100);
        }
    }
}

void Canvas::drawCircle() {
    shapes.append({"circle"});
    update();
}

void Canvas::drawSquare() {
    shapes.append({"square"});
    update();
}

