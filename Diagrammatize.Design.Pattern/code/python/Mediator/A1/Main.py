from tkinter import *
from LoginFrame import LoginFrame

def main():
    root = Tk()
    frame = LoginFrame(root, "Mediator Sample")
    frame.pack()
    root.mainloop()

if __name__ == "__main__":
    main()

