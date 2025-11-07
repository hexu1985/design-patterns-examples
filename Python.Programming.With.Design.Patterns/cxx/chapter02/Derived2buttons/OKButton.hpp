#include "DButton.hpp"

// OK 按钮类，点击显示消息
class OKButton : public DButton {
public:
    OKButton(QWidget *parent); 

    void comd() override; 
};
