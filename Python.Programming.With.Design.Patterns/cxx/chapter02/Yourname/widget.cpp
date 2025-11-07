#include "widget.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QString>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    // 创建主布局
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 顶部标签
    QLabel *questionLabel = new QLabel("What is your name?");
    questionLabel->setStyleSheet("color: blue;");
    questionLabel->setContentsMargins(20, 10, 20, 10); // padx=20, pady=10
    layout->addWidget(questionLabel);

    // 创建输入字段
    nmEntry = new QLineEdit();
    layout->addWidget(nmEntry);

    // OK 按钮
    QPushButton *okButton = new QPushButton("OK");
    layout->addWidget(okButton);

    // 这是文本会改变的标签
    cLabel = new QLabel("name");
    cLabel->setStyleSheet("color: blue;");
    layout->addWidget(cLabel);

    // 连接按钮点击信号到槽函数
    connect(okButton, &QPushButton::clicked, this, &Widget::getName);
}

void Widget::getName() {
    QString newName = nmEntry->text();
    cLabel->setText("Hi " + newName + " boy!");
}

