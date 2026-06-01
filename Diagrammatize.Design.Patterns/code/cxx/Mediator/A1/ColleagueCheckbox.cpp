#include "ColleagueCheckbox.hpp"

#include "Mediator.hpp"

ColleagueCheckbox::ColleagueCheckbox(const std::string& caption, QWidget *parent)
    : QRadioButton(caption.c_str(), parent) {

}

ColleagueCheckbox::~ColleagueCheckbox() {}

void ColleagueCheckbox::setMediator(Mediator* mediator_) {    // 保存Mediator
    mediator = mediator_;
}

void ColleagueCheckbox::setColleagueEnabled(bool enabled) {   // Mediator下达启用/禁用的指示
    setEnabled(enabled);
}

void ColleagueCheckbox::itemStateChanged(bool on) {             // 当状态发生变化时通知Mediator
    if (on) mediator->colleagueChanged();
}
