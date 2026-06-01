
import tkinter as tk
from .Drawable import Drawable
from .ColorCommand import ColorCommand

class DrawCanvas(tk.Canvas, Drawable):
    def __init__(self, parent, width, height, history):
        tk.Canvas.__init__(self, parent, width=width, height=height, bg='white')
        self.history = history
        self.radius = None
        self.color = None
        self.init()

    def repaint(self):
        self.delete("all")
        self.history.execute()

    def init(self):
        self.radius = 6
        self.color = "red"
        self.history.append(ColorCommand(self, self.color))

    def draw(self, x, y):
        self.create_oval(x - self.radius, y - self.radius, 
                x + self.radius, y + self.radius, fill=self.color, outline=self.color)

    def setColor(self, color):
        self.color = color

