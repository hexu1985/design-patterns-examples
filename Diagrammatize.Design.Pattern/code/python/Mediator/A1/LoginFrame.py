import sys
import tkinter as tk
from Mediator import Mediator
from ColleagueCheckbox import ColleagueCheckbox
from ColleagueTextField import ColleagueTextField
from ColleagueButton import ColleagueButton

class LoginFrame(tk.Frame):
    def __init__(self, parent, title):
        tk.Frame.__init__(self, parent)
        font=('Arial', 16)
        self.createColleagues(font=font)

        self.checkGuest.grid(row=0, column=0)
        self.checkLogin.grid(row=0, column=1)
        tk.Label(self, text="Username:", font=font).grid(row=1, column=0, padx=10)
        self.textUser.grid(row=1, column=1, padx=10)
        tk.Label(self, text="Password:", font=font).grid(row=2, column=0, padx=10)
        self.textPass.grid(row=2, column=1, padx=10)
        self.buttonOk.grid(row=3, column=0)
        self.buttonCancel.grid(row=3, column=1)

        self.colleagueChanged()

    def createColleagues(self, font):
        self.checkbox_var = tk.IntVar(value=1)
        self.checkGuest = ColleagueCheckbox(self, "Guest", self.checkbox_var, 1, font=font)
        self.checkLogin = ColleagueCheckbox(self, "Login", self.checkbox_var, 2, font=font)
        self.textUser = ColleagueTextField(self, "", 16, font=font)
        self.textPass = ColleagueTextField(self, "", 16, font=font)
        self.textPass.config(show="*")
        self.buttonOk = ColleagueButton(self, "OK", command=self.onButtonOKClick, font=font)
        self.buttonCancel = ColleagueButton(self, "Cancel", command=self.onButtonCancelClick, font=font)

        self.checkGuest.setMediator(self)
        self.checkLogin.setMediator(self)
        self.textUser.setMediator(self)
        self.textPass.setMediator(self)
        self.buttonOk.setMediator(self)
        self.buttonCancel.setMediator(self)

    def colleagueChanged(self):
        if self.checkGuest.getState():
            self.textUser.setColleagueEnabled(False)
            self.textPass.setColleagueEnabled(False)
            self.buttonOk.setColleagueEnabled(True)
        else:
            self.textUser.setColleagueEnabled(True)
            self.userpassChanged()

    def userpassChanged(self):
        if len(self.textUser.getText()) > 0:
            self.textPass.setColleagueEnabled(True)
            if len(self.textUser.getText()) >= 4 and len(self.textPass.getText()) >= 4:
                self.buttonOk.setColleagueEnabled(True)
            else:
                self.buttonOk.setColleagueEnabled(False)
        else:
            self.textPass.setColleagueEnabled(False)
            self.buttonOk.setColleagueEnabled(False)

    def onButtonOKClick(self):
        self.actionPerformed("buttonOk")

    def onButtonCancelClick(self):
        self.actionPerformed("buttonCancel")

    def actionPerformed(self, e):
        print(e)
        sys.exit()

if __name__ == "__main__":
    root = tk.Tk()
    frame = LoginFrame(root, "hello")
    frame.pack()
    root.mainloop()
