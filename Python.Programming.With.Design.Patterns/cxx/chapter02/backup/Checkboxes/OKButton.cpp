#include "OKButton.hpp"
#include "Checkbox.hpp"
#include <QDebug>


OKButton::OKButton(QWidget* parent, const std::vector<Checkbox*>& boxes) 
    : QPushButton("Order", parent), m_boxes(boxes) {

    connect(this, &QPushButton::clicked, this, &OKButton::comd);
}

void OKButton::comd() {
    for (Checkbox* box : m_boxes) {
        qDebug() << box->getText() << box->getVar();
    }
}
