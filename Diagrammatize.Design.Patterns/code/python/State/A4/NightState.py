from State import State

class NightState(State):
    _singleton = None

    def __init__(self):
        print("create NightState")
        pass

    @classmethod
    def getInstance(cls):
        if not cls._singleton:
            cls._singleton = cls()
        return cls._singleton

    def doClock(self, context, hour):
        from DayState import DayState
        if 9 <= hour < 17:
            context.changeState(DayState.getInstance())

    def doUse(self, context):
        context.callSecurityCenter("紧急：晚上使用金库！")

    def doAlarm(self, context):
        from UrgentState import UrgentState
        context.callSecurityCenter("按下警铃(晚上)")
        context.changeState(UrgentState.getInstance())

    def doPhone(self, context):
        context.recordLog("晚上的通话录音")

    def __str__(self):
        return "[晚上]"


