from tkinter import *
from LoginFrame import LoginFrame

def main():
    root = Tk()
    root.title("Mediator Sample")
    frame = LoginFrame(root)
    root.mainloop()

if __name__ == "__main__":
    main()

