#pragma once

#include <QPushButton>

// 抽象按钮基类，类似于 Python 中的 DButton
class DButton : public QPushButton {
Q_OBJECT
public:
    DButton(QWidget *parent = nullptr); 

    virtual ~DButton();

    virtual void comd() = 0; // 纯虚函数，子类必须实现

private slots:
    void on_clicked();
};

