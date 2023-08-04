#pragma once

#include "Observer.hpp"

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class GraphText;
class GraphCanvas;

class FrameObserver: public QWidget, public Observer
{
    Q_OBJECT

public:
    FrameObserver(QWidget* parent = 0);

    void update(NumberGenerator* generator) override;

private:
    GraphText* textGraph;
    GraphCanvas* canvasGraph;
    QPushButton* buttonClose;
};

class GraphCanvas : public QWidget, public Observer
{
    Q_OBJECT

public:
    GraphCanvas(QWidget *parent = 0);

    void draw(QPainter *painter);

    void update(NumberGenerator* generator) override;

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int number = 0;
};


class GraphText : public QWidget, public Observer
{
    Q_OBJECT

public:
    GraphText(QWidget *parent = 0);
    ~GraphText();

    void update(NumberGenerator* generator) override;

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    QLabel *lbl;

};

