#include "QuitButton.hpp"
#include <QApplication>

QuitButton::QuitButton(QWidget *parent) : DButton("Quit", parent) {
    this->disable();
}

void QuitButton::comd() {
    QApplication::quit();
}
