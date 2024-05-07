from State import State

class UrgentState(State):
    _singleton = None

    def __init__(self):
        print("create UrgentState")
        pass

    @classmethod
    def getInstance(cls):
        if not cls._singleton:
            cls._singleton = cls()
        return cls._singleton

    def doClock(self, context, hour):
        pass

    def doUse(self, context):
        context.callSecurityCenter("紧急:紧急时使用金库！")

    def doAlarm(self, context):
        context.callSecurityCenter("按下警铃(紧急时)")

    def doPhone(self, context):
        context.callSecurityCenter("正常通话(紧急时)")

    def __str__(self):
        return "[紧急时]"


