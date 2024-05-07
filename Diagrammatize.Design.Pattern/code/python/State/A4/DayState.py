from State import State

class DayState(State):
    _singleton = None

    def __init__(self):
        print("create DayState")
        pass

    @classmethod
    def getInstance(cls):
        if not cls._singleton:
            cls._singleton = cls()
        return cls._singleton

    def doClock(self, context, hour):
        from NightState import NightState
        if hour < 9 or 17 <= hour:
            context.changeState(NightState.getInstance())

    def doUse(self, context):
        context.recordLog("使用金库(白天)")

    def doAlarm(self, context):
        from UrgentState import UrgentState
        context.callSecurityCenter("按下警铃(白天)")
        context.changeState(UrgentState.getInstance())

    def doPhone(self, context):
        context.callSecurityCenter("正常通话(白天)")

    def __str__(self):
        return "[白天]"

