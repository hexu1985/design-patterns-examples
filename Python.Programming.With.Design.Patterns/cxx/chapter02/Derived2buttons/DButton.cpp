#include "DButton.hpp"

DButton::DButton(QWidget *parent) : QPushButton(parent) {
    connect(this, &QPushButton::clicked, this, &DButton::on_clicked);
}

DButton::~DButton() {
}

void DButton::on_clicked() {
    comd();
}
