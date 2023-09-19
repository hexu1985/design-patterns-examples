#include "DayState.hpp"
#include "NightState.hpp"
#include "NoonState.hpp"
#include "Context.hpp"

DayState::DayState() {
}

State* DayState::getInstance() {
    static DayState singleton;
    return &singleton;
}

void DayState::doClock(Context* context, int hour) {
    if (hour < 9 || 17 <= hour) {
        context->changeState(NightState::getInstance());
    } else if (12 <= hour && hour < 13) {                   
        context->changeState(NoonState::getInstance());       
    }                                                       
}

void DayState::doUse(Context* context) {
    context->recordLog("使用金库(白天)");
}

void DayState::doAlarm(Context* context) {
    context->callSecurityCenter("按下警铃(白天)");
}

void DayState::doPhone(Context* context) {
    context->callSecurityCenter("正常通话(白天)");
}

std::string DayState::toString() const {
    return "[白天]";
}
