from State import State

class NoonState(State):
    _singleton = None

    def __init__(self):
        print("create NoonState")
        pass

    @classmethod
    def getInstance(cls):
        if not cls._singleton:
            cls._singleton = cls()
        return cls._singleton

    def doClock(self, context, hour):
        from DayState import DayState
        from NightState import NightState
        if hour < 9 or 17 <= hour:
            context.changeState(NightState.getInstance())
        elif (9 <= hour < 12) or (13 <= hour < 17):
            context.changeState(DayState.getInstance())

    def doUse(self, context):
        context.callSecurityCenter("紧急：午餐时间使用金库！")

    def doAlarm(self, context):
        context.callSecurityCenter("按下警铃(午餐时间)")

    def doPhone(self, context):
        context.recordLog("午餐时间的通话录音")

    def __str__(self):
        return "[午餐时间]"


