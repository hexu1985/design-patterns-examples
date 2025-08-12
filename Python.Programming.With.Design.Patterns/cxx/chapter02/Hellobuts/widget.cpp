#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Hellobuts");
    setGeometry(300, 300, 200, 100);

    QPushButton *hello_button = new QPushButton("Hello", this);
    QPushButton *quit_button = new QPushButton("Quit", this);

    connect(hello_button, SIGNAL(clicked()), this, SLOT(disp_slogan()));
    QObject::connect(quit_button, &QPushButton::clicked, &QApplication::quit);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(hello_button);
    layout->addWidget(quit_button);

    setLayout(layout);
}

void Widget::disp_slogan()
{
    QMessageBox::information(this, "our message", "Qt is easy to use");
}

Widget::~Widget()
{
}

