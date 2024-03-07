import tkinter as tk
from Colleague import Colleague

class ColleagueCheckbox(tk.Radiobutton, Colleague):
    def __init__(self, parent, caption, var:tk.IntVar, value:int, font=None):
        self.mediator = None
        self.var = var
        self.value = value
        tk.Radiobutton.__init__(self, parent, text=caption, variable=var, value=value, command=self.itemStateChanged, font=font)

    def setMediator(self, mediator):
        self.mediator = mediator

    def itemStateChanged(self):
        if self.mediator:
            self.mediator.colleagueChanged()
        else:
            print("itemStateChanged, but mediator is None")

    def setColleagueEnabled(self, enabled):
        if enabled:
            self.config(state=tk.NORMAL)
        else:
            self.config(state=tk.DISABLED)

    def getState(self):
        if self.value == self.var.get():
            return True
        else:
            return False

def main():
    root = tk.Tk()
    var = tk.IntVar()
    var.set(0)
    checkbox = ColleagueCheckbox(root, "hello", var, 1)
    checkbox.pack()
    checkbox.setColleagueEnabled(True)
    print("checkbox.getState:", checkbox.getState())
    root.mainloop()

if __name__ == "__main__":
    main()

