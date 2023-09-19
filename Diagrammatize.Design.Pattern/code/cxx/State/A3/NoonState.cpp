#include "NoonState.hpp"
#include "DayState.hpp"
#include "NightState.hpp"
#include "Context.hpp"

NoonState::NoonState() {
}

State* NoonState::getInstance() {
    static NoonState singleton;
    return &singleton;
}

void NoonState::doClock(Context* context, int hour) {
    if (hour < 9 || 17 <= hour) {
        context->changeState(NightState::getInstance());
    } else if (9 <= hour && hour < 12 || 13 <= hour && hour < 17) {
        context->changeState(DayState::getInstance());
    }
}

void NoonState::doUse(Context* context) {
    context->callSecurityCenter("紧急：午餐时间使用金库！");
}

void NoonState::doAlarm(Context* context) {
    context->callSecurityCenter("按下警铃(午餐时间)");
}

void NoonState::doPhone(Context* context) {
    context->recordLog("午餐时间的通话录音");
}

std::string NoonState::toString() const {
    return "[午餐时间]";
}
