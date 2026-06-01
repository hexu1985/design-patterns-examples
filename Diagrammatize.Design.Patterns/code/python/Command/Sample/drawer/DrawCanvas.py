
import tkinter as tk
from .Drawable import Drawable

class DrawCanvas(tk.Canvas, Drawable):
    def __init__(self, parent, width, height, history):
        tk.Canvas.__init__(self, parent, width=width, height=height, bg='white')
        self.history = history
        self.radius = 6
        self.color = "red"

    def repaint(self):
        self.delete("all")
        self.history.execute()

    def draw(self, x, y):
        self.create_oval(x - self.radius, y - self.radius, 
                x + self.radius, y + self.radius, fill=self.color, outline=self.color)
