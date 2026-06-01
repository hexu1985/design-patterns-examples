#include "ColleagueButton.hpp"

ColleagueButton::ColleagueButton(const std::string& caption, QWidget *parent): QPushButton(caption.c_str(), parent) 
{}

ColleagueButton::~ColleagueButton() {}

void ColleagueButton::setMediator(Mediator* mediator_) {    // 保存Mediator
    mediator = mediator_;
}

void ColleagueButton::setColleagueEnabled(bool enabled) {   // Mediator下达启用/禁用的指示
    setEnabled(enabled);
}
