#pragma once

#include "DButton.hpp"

// 退出按钮类，点击退出程序
class QuitButton : public DButton {
public:
    QuitButton(QWidget *parent); 

    void comd() override; 
};
