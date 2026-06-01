#include "FrameObserver.hpp"
#include "NumberGenerator.hpp"
#include <QtWidgets>
#include <QApplication>
#include <sstream>
#include <iostream>

FrameObserver::FrameObserver(QWidget* parent)
    : QWidget(parent)
{
    resize(500, 500);
    textGraph = new GraphText(this);
    canvasGraph = new GraphCanvas(this);
    buttonClose = new QPushButton("Close", this);

    QVBoxLayout *defaultLayout = new QVBoxLayout();

    defaultLayout->addWidget(textGraph);
    defaultLayout->addWidget(canvasGraph);
    defaultLayout->addWidget(buttonClose);

    setLayout(defaultLayout);

    QObject::connect(buttonClose, &QPushButton::clicked, &QApplication::quit);
}

void FrameObserver::update(NumberGenerator* generator) {
    textGraph->update(generator);
    canvasGraph->update(generator);
}

GraphText::GraphText(QWidget *parent)
    : QWidget(parent)
{
    lbl = new QLabel("", this);
    lbl->setText(QString("%1").arg(50));
    lbl->setFixedWidth(400);

    connect(this, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
}

GraphText::~GraphText()
{

}

void GraphText::update(NumberGenerator* generator) {
    int number = generator->getNumber();
    emit valueChanged(number);
}

void GraphText::setValue(int value)
{
    std::string text = std::to_string(value) + ":";
    for (int i = 0; i < value; i++) {
        text += '*';
    }
    lbl->setText(QString::fromStdString(text));
}

GraphCanvas::GraphCanvas(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(400,400);
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
}

void GraphCanvas::setValue(int value) 
{
    number = value;
    QWidget::update();
}

void GraphCanvas::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    int side = qMin(width(), height())*9/10;

    painter.setViewport((width() - side) / 2, (height() - side) / 2,
                        side, side);
    painter.setWindow(-50, -50, 100, 100);

    draw(&painter);
}

void GraphCanvas::draw(QPainter *painter)
{
    int W = 100;
    int H = 100;
    QRect rect(-50,-50,W,H);
    painter->drawEllipse(rect);
    QBrush brush(Qt::red, Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawPie(-50, -50, W, H, 90*16, - number * 360 / 50 *16);
}

void GraphCanvas::update(NumberGenerator* generator) {
    int number = generator->getNumber();
    emit valueChanged(number);
}

