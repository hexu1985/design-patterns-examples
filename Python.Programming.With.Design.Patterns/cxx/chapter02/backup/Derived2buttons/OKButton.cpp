#include "OKButton.hpp"
#include <QMessageBox>

OKButton::OKButton(QWidget *parent) : DButton(parent) {
    setText("OK");
}

void OKButton::comd() {
    QMessageBox::information(this, "our message", "Qt is easy to use");
}

