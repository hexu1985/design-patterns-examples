#include "NightState.hpp"
#include "DayState.hpp"
#include "UrgentState.hpp"
#include "Context.hpp"

NightState::NightState() {
}

State* NightState::getInstance() {
    static NightState singleton;
    return &singleton;
}

void NightState::doClock(Context* context, int hour) {
    if (9 <= hour && hour < 17) {
        context->changeState(DayState::getInstance());
    }
}

void NightState::doUse(Context* context) {
    context->callSecurityCenter("紧急：晚上使用金库！");
}

void NightState::doAlarm(Context* context) {
    context->callSecurityCenter("按下警铃(晚上)");
    context->changeState(UrgentState::getInstance());
}

void NightState::doPhone(Context* context) {
    context->recordLog("晚上的通话录音");
}

std::string NightState::toString() const {
    return "[晚上]";
}

