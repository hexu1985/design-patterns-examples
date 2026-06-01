
from tkinter import *
from MainWindow import MainWindow

def main():
    root = Tk()
    root.title("Command Pattern Sample")
    m = MainWindow(root)
    m.pack()
    root.mainloop()

if __name__ == "__main__":
    main()
