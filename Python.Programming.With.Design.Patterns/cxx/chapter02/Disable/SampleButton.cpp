#include "Mediator.hpp"
#include "SampleButton.hpp"

SampleButton::SampleButton(Mediator* mediator, QWidget* parent) 
    : DButton("Sample", parent), med(mediator) {
    this->enable();
}

void SampleButton::comd() {
    med->sclicked();
}
