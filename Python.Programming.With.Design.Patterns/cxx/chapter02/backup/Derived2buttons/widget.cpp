#include "widget.h"
#include "OKButton.hpp"
#include "QuitButton.hpp"
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("derived2buts");
    setGeometry(300, 300, 200, 100);

    QHBoxLayout *layout = new QHBoxLayout(this);

    // 创建 OK 按钮
    OKButton *okButton = new OKButton(this);
    layout->addWidget(okButton);

    // 创建退出按钮
    QuitButton *quitButton = new QuitButton(this);
    layout->addWidget(quitButton);

    setLayout(layout);
}

Widget::~Widget()
{
}

