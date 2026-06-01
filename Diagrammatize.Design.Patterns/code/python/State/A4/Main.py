import threading
import time
import tkinter as tk

from SafeFrame import SafeFrame

def update_clock(frame):
    for hour in range(24):
        frame.setClock(hour)
        time.sleep(1.0)

def main():
    root = tk.Tk()
    root.title("State Sample")
    frame = SafeFrame(root)
    frame.pack()

    clock_thread = threading.Thread(target=update_clock, args=(frame, ), daemon=True)
    clock_thread.start()

    root.mainloop()

if __name__ == "__main__":
    main()
