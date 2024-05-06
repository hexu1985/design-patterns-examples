import tkinter as tk
import sys
from functools import partial
from Observer import Observer

class GraphText(Observer):
    def __init__(self, textfield):
        self.textfield = textfield

    def update(self, generator):
        number = generator.getNumber()
        self.textfield.after(0, partial(self.setValue, number))

    def setValue(self, number):
        text = str(number) + ":"
        for i in range(number):
            text += "*"
        self.textfield.delete(0, tk.END)  # Entry.delete
        self.textfield.insert(0, text)    # Entry.insert


class GraphCanvas(Observer):
    def __init__(self, canvas):
        self.canvas = canvas

    def update(self, generator):
        number = generator.getNumber()
        self.canvas.after(0, partial(self.setValue, number))

    def setValue(self, number):
        self.canvas.delete("all")      # Canvas.delete
        width = self.canvas.winfo_width()      # Canvas.winfo_width
        height = self.canvas.winfo_height()    # Canvas.winfo_height
        self.canvas.create_oval(0, 0, width, height, fill="white")
        self.canvas.create_arc(0, 0, width, height, start=90, extent=(-number * 360 / 50), fill="red")
        self.canvas.update()            # Canvas.update

class FrameObserver(tk.Frame, Observer):
    def __init__(self, parent):
        tk.Frame.__init__(self, parent)
        self.pack()

        textfield = tk.Entry(parent)
        self.textGraph = GraphText(textfield)
        textfield.pack(fill=tk.X)

        canvas = tk.Canvas(parent, width=500, height=500)
        self.canvasGraph = GraphCanvas(canvas)
        canvas.pack(fill=tk.X)

        self.buttonClose = tk.Button(parent, text="close", command=partial(sys.exit, 1))
        self.buttonClose.pack(fill=tk.X)

    def update(self, generator):
        self.textGraph.update(generator)
        self.canvasGraph.update(generator)


if __name__ == "__main__":
    root = tk.Tk()
    frame = FrameObserver(root)
    root.mainloop()

