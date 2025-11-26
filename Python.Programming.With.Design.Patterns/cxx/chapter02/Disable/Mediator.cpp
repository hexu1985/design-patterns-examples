#include "Mediator.hpp"
#include "DButton.hpp"

Mediator::Mediator(QWidget* parent): QObject(parent) {
}

void Mediator::setQuitButton(DButton* button) {
    quitButton = button;
}

void Mediator::sclicked() {
    if (quitButton) {
        quitButton->enable();
    }
}
