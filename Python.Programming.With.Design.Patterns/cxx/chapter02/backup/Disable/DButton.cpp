#include "DButton.hpp"

DButton::DButton(const char* text, QWidget *parent): QPushButton(text, parent) {
    connect(this, &QPushButton::clicked, this, &DButton::on_clicked);
}

DButton::DButton(QWidget *parent): DButton("", parent) {
}

DButton::~DButton() {
}

void DButton::on_clicked() {
    comd();
}

void DButton::disable() {
    this->setEnabled(false);
}

void DButton::enable() {
    this->setEnabled(true);
}
