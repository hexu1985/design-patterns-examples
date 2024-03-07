import tkinter as tk
from Colleague import Colleague

class ColleagueButton(tk.Button, Colleague):
    def __init__(self, parent, caption, command=None, font=None):
        self.mediator = None
        tk.Button.__init__(self, parent, text=caption, command=command, font=font)

    def setMediator(self, mediator):
        self.mediator = mediator

    def setColleagueEnabled(self, enabled):
        if enabled:
            self.config(state=tk.NORMAL)
        else:
            self.config(state=tk.DISABLED)

def main():
    import sys
    def quit():
        print("bye")
        sys.exit(1)

    root = tk.Tk()
    button = ColleagueButton(root, "hello", quit)
    button.pack()
    root.mainloop()

if __name__ == "__main__":
    main()
