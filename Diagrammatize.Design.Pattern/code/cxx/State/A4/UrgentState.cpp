#include "UrgentState.hpp"
#include "Context.hpp"

UrgentState::UrgentState() {
}

State* UrgentState::getInstance() {
    static UrgentState singleton;
    return &singleton;
}

void UrgentState::doClock(Context* context, int hour) {
}

void UrgentState::doUse(Context* context) {
    context->callSecurityCenter("紧急:紧急时使用金库！");
}

void UrgentState::doAlarm(Context* context) {
    context->callSecurityCenter("按下警铃(紧急时)");
}

void UrgentState::doPhone(Context* context) {
    context->callSecurityCenter("正常通话(紧急时)");
}

std::string UrgentState::toString() const {
    return "[紧急时]";
}
