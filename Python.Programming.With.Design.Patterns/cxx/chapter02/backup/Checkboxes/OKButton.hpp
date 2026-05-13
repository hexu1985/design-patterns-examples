#pragma once

#include <QPushButton>
#include <vector>

class Checkbox;

// Button with clicked signal to print out list of toppings ordered
class OKButton : public QPushButton {
    Q_OBJECT
public:
    OKButton(QWidget* parent, const std::vector<Checkbox*>& boxes);

private slots:
    void comd(); 

private:
    std::vector<Checkbox*> m_boxes;
};
