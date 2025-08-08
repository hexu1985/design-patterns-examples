#pragma once

#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = 0);
    ~Canvas();

protected:
    void paintEvent(QPaintEvent *event);
};

