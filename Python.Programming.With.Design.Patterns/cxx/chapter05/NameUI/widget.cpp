#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QApplication>

#include "Namer.hpp"

Widget::Widget(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Simple Factory");

    // 创建主布局
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // 输入标签
    QLabel* instructionLabel = new QLabel("Enter name");
    instructionLabel->setStyleSheet("color: blue;");
    mainLayout->addWidget(instructionLabel);

    // 输入框
    entry = new QLineEdit();
    mainLayout->addWidget(entry);

    // 名字部分
    QHBoxLayout* firstNameLayout = new QHBoxLayout();
    QLabel* firstNameLabel = new QLabel("First name:");
    firstNameLabel->setStyleSheet("color: blue;");
    firstNameLayout->addWidget(firstNameLabel);

    frname = new QLineEdit();
    firstNameLayout->addWidget(frname);
    mainLayout->addLayout(firstNameLayout);

    // 姓氏部分
    QHBoxLayout* lastNameLayout = new QHBoxLayout();
    QLabel* lastNameLabel = new QLabel("Last name:");
    lastNameLabel->setStyleSheet("color: blue;");
    lastNameLayout->addWidget(lastNameLabel);

    lname = new QLineEdit();
    lastNameLayout->addWidget(lname);
    mainLayout->addLayout(lastNameLayout);

    // 按钮部分
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    QPushButton* btcompute = new QPushButton("Compute");
    connect(btcompute, &QPushButton::clicked, this, &Widget::compute);
    buttonLayout->addWidget(btcompute);

    QPushButton* btclear = new QPushButton("Clear");
    connect(btclear, &QPushButton::clicked, this, &Widget::clearPanel);
    buttonLayout->addWidget(btclear);

    QPushButton* btquit = new QPushButton("Quit");
    connect(btquit, &QPushButton::clicked, qApp, &QApplication::quit);
    buttonLayout->addWidget(btquit);

    mainLayout->addLayout(buttonLayout);

    // 设置窗口大小
    setMinimumSize(400, 200);
}

// 清空所有字段
void Widget::clearPanel() {
    frname->clear();
    lname->clear();
    entry->clear();
}

// 使用 Namer factory 填充字段
void Widget::compute() {
    QString name = entry->text();  // 获取名称字符串

    // 获取 Namer Factory 然后获取 namer 类
    NamerFactory namerFact(name);  // 获取 namer factory
    Namer* namer = namerFact.getNamer();  // 获取 namer

    // 获取名称并复制到字段中
    frname->setText(namer->first);
    lname->setText(namer->last);

    delete namer;  // 清理内存
}

