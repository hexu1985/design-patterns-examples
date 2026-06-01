
import tkinter as tk
from command import MacroCommand
from drawer import DrawCommand, DrawCanvas

class MainWindow(tk.Frame):
    def __init__(self, parent):
        tk.Frame.__init__(self, parent)

        buttonBox = tk.Frame(self)
        self.clearButton = tk.Button(buttonBox, text="clear", command=self.onClearButtonClicked)
        self.clearButton.pack(side=tk.LEFT, fill=tk.X, expand=1)

        self.undoButton = tk.Button(buttonBox, text="undo", command=self.onUndoButtonClicked)
        self.undoButton.pack(side=tk.LEFT, fill=tk.X, expand=1)
        buttonBox.pack(fill=tk.X)

        self.history = MacroCommand()
        self.canvas = DrawCanvas(self, 400, 400, self.history)
        self.canvas.pack()

        self.canvas.bind("<B1-Motion>", self.mouseDragged)

    def onClearButtonClicked(self):
        self.history.clear()
        self.canvas.repaint()

    def onUndoButtonClicked(self):
        self.history.undo()
        self.canvas.repaint()

    def mouseDragged(self, event):
        cmd = DrawCommand(self.canvas, event)
        self.history.append(cmd)
        cmd.execute()
