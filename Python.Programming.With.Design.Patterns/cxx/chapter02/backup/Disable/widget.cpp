#include "widget.h"
#include "SampleButton.hpp"
#include "QuitButton.hpp"
#include "Mediator.hpp"
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Qt Button Example");
    setGeometry(300, 300, 200, 100);

    QHBoxLayout* layout = new QHBoxLayout(this);
    Mediator* med = new Mediator(this);

    // 创建 OK 按钮
    SampleButton *sampleBtn = new SampleButton(med, this);
    layout->addWidget(sampleBtn);

    // 创建退出按钮
    QuitButton *quitBtn = new QuitButton(this);
    layout->addWidget(quitBtn);

    // 设置中介者的退出按钮
    med->setQuitButton(quitBtn);

    setLayout(layout);
}

Widget::~Widget()
{
}

