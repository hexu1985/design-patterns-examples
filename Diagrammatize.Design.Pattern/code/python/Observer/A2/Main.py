import threading
import tkinter as tk

from RandomNumberGenerator import RandomNumberGenerator
from DigitObserver import DigitObserver
from GraphObserver import GraphObserver
from FrameObserver import FrameObserver

def generator_execute(generator):
    generator.execute()

def main():
    root = tk.Tk()
    frame = FrameObserver(root)
    frame.pack()

    generator = RandomNumberGenerator()
    observer1 = DigitObserver()
    observer2 = GraphObserver()
    observer3 = frame
    generator.addObserver(observer1)
    generator.addObserver(observer2)
    generator.addObserver(observer3)

    generate_thread = threading.Thread(target=generator_execute, args=(generator, ), daemon=True)
    generate_thread.start()

    root.mainloop()

if __name__ == "__main__":
    main()
