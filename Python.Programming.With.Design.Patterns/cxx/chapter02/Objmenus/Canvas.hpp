#pragma once

#include <QPainter>
#include <QWidget>
#include <QString>

// Canvas widget for drawing shapes
class Canvas : public QWidget {
public:
    Canvas(QWidget *parent = nullptr); 

protected:
    void paintEvent(QPaintEvent *event) override; 

public:
    void drawCircle();
    void drawSquare(); 

private:
    struct Shape {
        QString type;
    };
    QList<Shape> shapes;
};
