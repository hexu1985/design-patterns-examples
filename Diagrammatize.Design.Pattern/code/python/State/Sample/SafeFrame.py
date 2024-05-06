import tkinter as tk

class SafeFrame(tk.Frame):
    def __init__(self, parent):
        tk.Frame.__init__(self, parent)

        self.textClock = tk.Entry(parent, width=60)

        self.textScreen = tk.Text(parent, height=10, width=60)

        self.buttonUse = tk.Button(parent, text="使用金库", command=None)
        self.buttonAlarm = tk.Button(parent, text="按下警铃", command=None)
        self.buttonPhone = tk.Button(parent, text="正常通话", command=None)
        self.buttonExit = tk.Button(parent, text="结束", command=None)

        self.textClock.grid(row=0, column=0, columnspan=4)
        self.textScreen.grid(row=1, column=0, columnspan=4)
        self.buttonUse.grid(row=2, column=0) 
        self.buttonAlarm.grid(row=2, column=1)
        self.buttonPhone.grid(row=2, column=2)
        self.buttonExit.grid(row=2, column=3)

if __name__ == "__main__":
    root = tk.Tk()
    frame = SafeFrame(root)
    root.mainloop()

