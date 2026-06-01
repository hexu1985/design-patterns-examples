#include "FrameBuilder.hpp"
#include <QDebug>
#include <QCoreApplication>
#include <string>

FrameBuilder::FrameBuilder(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget = new QWidget(this);
    mainLayout = new QVBoxLayout(centralWidget);
    setCentralWidget(centralWidget);
}

FrameBuilder::~FrameBuilder()
{
}

void FrameBuilder::makeTitle(const std::string& title)
{
    setWindowTitle(QString::fromStdString(title));
}

void FrameBuilder::makeString(const std::string& str)
{
    QLabel *label = new QLabel(QString::fromStdString(str), this);
    mainLayout->addWidget(label);
}

void FrameBuilder::makeItems(const std::vector<std::string>& items)
{
    QWidget *innerWidget = new QWidget(this);
    QVBoxLayout *innerLayout = new QVBoxLayout(innerWidget);
    
    for (const auto& itemText : items) {
        QPushButton *button = new QPushButton(QString::fromStdString(itemText), this);
        connect(button, &QPushButton::clicked, this, &FrameBuilder::onButtonClicked);
        innerLayout->addWidget(button);
    }
    
    mainLayout->addWidget(innerWidget);
}

void FrameBuilder::close()
{
    // 设置窗口关闭时退出应用
    connect(this, &QMainWindow::destroyed, []() {
        QCoreApplication::exit(0);
    });
    
    // 调整窗口大小以适应内容（类似 Java 的 pack()）
    adjustSize();
}

QMainWindow* FrameBuilder::getResult()
{
    return this;
}

void FrameBuilder::onButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        std::string buttonText = button->text().toStdString();
        qDebug() << QString::fromStdString(buttonText);
        // 或者直接输出到控制台
        // std::cout << buttonText << std::endl;
    }
}
