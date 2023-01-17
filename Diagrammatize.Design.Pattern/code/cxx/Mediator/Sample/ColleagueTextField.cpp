#include "ColleagueTextField.hpp"
#include "Mediator.hpp"

ColleagueTextField::ColleagueTextField(const std::string& caption, QWidget *parent)
    : QLineEdit(caption.c_str(), parent) {
}

ColleagueTextField::~ColleagueTextField() {}

void ColleagueTextField::setMediator(Mediator* mediator_) {    // 保存Mediator
    mediator = mediator_;
}

void ColleagueTextField::setColleagueEnabled(bool enabled) {   // Mediator下达启用/禁用的指示
    setEnabled(enabled);
}

void ColleagueTextField::textValueChanged(const QString& text) {             // 当文字发生变化时通知Mediator
    mediator->colleagueChanged();
}
