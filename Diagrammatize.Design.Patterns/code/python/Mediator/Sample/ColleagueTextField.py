import tkinter as tk
from Colleague import Colleague

class ColleagueTextField(tk.Entry, Colleague):
    def __init__(self, parent, text, columns, font=None):
        self.mediator = None
        self.textVar = tk.StringVar()
        self.textVar.set(text)
        tk.Entry.__init__(self, parent, width=columns, textvariable=self.textVar, font=font)
        self.bind('<Key>', self.notifyTextValueChanged)

    def setMediator(self, mediator):
        self.mediator = mediator

    def setColleagueEnabled(self, enabled):
        if enabled:
            self.config(state=tk.NORMAL)
        else:
            self.config(state=tk.DISABLED)

    def notifyTextValueChanged(self, event):
        # call self.textValueChanged on event loop
        self.after(0, self.textValueChanged)

    def textValueChanged(self):
        if self.mediator:
            self.mediator.colleagueChanged()
        else:
            print("textValueChanged, but mediator is None, textVar:[{}]".format(self.textVar.get()))

    def getText(self):
        return self.textVar.get()

def main():
    root = tk.Tk()
    text_field = ColleagueTextField(root, "hello", 10)
    text_field.pack()
    root.mainloop()


if __name__ == "__main__":
    main()
