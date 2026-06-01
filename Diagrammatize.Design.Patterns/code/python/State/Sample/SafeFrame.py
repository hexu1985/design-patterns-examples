import tkinter as tk
import sys
from functools import partial

from Context import Context
from DayState import DayState
from NightState import NightState
from ScrolledText import ScrolledText

class SafeFrame(tk.Frame):
    def __init__(self, parent):
        tk.Frame.__init__(self, parent)

        self.textClock = tk.Entry(self, width=62)

        self.textScreen = ScrolledText(self, height=10, width=60)

        self.buttonUse = tk.Button(self, text="使用金库", command=self.buttonUseClicked)
        self.buttonAlarm = tk.Button(self, text="按下警铃", command=self.buttonAlarmClicked)
        self.buttonPhone = tk.Button(self, text="正常通话", command=self.buttonPhoneClicked)
        self.buttonExit = tk.Button(self, text="结束", command=self.buttonExitClicked)

        self.textClock.grid(row=0, column=0, columnspan=4)
        self.textScreen.grid(row=1, column=0, columnspan=4)

        self.buttonUse.grid(row=2, column=0) 
        self.buttonAlarm.grid(row=2, column=1)
        self.buttonPhone.grid(row=2, column=2)
        self.buttonExit.grid(row=2, column=3)

        self.state = DayState.getInstance()

    def buttonUseClicked(self):
        print("buttonUseClicked")
        self.state.doUse(self)

    def buttonAlarmClicked(self):
        print("buttonAlarmClicked")
        self.state.doAlarm(self)

    def buttonPhoneClicked(self):
        print("buttonPhoneClicked")
        self.state.doPhone(self)

    def buttonExitClicked(self):
        print("buttonExitClicked")
        sys.exit(0)

    def setClock(self, hour):
        self.after(0, partial(self._setClock, hour))

    def _setClock(self, hour):
        clockstring = "现在时间是";
        if hour < 10:
            clockstring += "0" + str(hour) + ":00"
        else:
            clockstring += str(hour) + ":00"
        print(clockstring)
        self.textClock.delete(0, tk.END)        # Entry.delete
        self.textClock.insert(0, clockstring)   # Entry.insert
        self.state.doClock(self, hour)

    def changeState(self, state):
        print("从" + str(self.state) + "状態变为了" + str(state) + "状态。")
        self.state = state

    def callSecurityCenter(self, msg):
        self.textScreen.appendText("call! " + msg + "\n")

    def recordLog(self, msg):
        self.textScreen.appendText("record ... " + msg + "\n")

if __name__ == "__main__":
    root = tk.Tk()
    frame = SafeFrame(root)
    frame.pack()
    root.mainloop()

