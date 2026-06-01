
import tkinter as tk
from command import MacroCommand
from drawer import DrawCommand, DrawCanvas, ColorCommand

class MainWindow(tk.Frame):
    def __init__(self, parent):
        tk.Frame.__init__(self, parent)

        buttonBox = tk.Frame(self)
        self.clearButton = tk.Button(buttonBox, text="clear", command=self.onClearButtonClicked)
        self.clearButton.pack(side=tk.LEFT, fill=tk.X, expand=1)

        self.redButton = tk.Button(buttonBox, text="red", command=self.onRedButtonClicked)
        self.redButton.pack(side=tk.LEFT, fill=tk.X, expand=1)

        self.greenButton = tk.Button(buttonBox, text="green", command=self.onGreenButtonClicked)
        self.greenButton.pack(side=tk.LEFT, fill=tk.X, expand=1)

        self.blueButton = tk.Button(buttonBox, text="blue", command=self.onBlueButtonClicked)
        self.blueButton.pack(side=tk.LEFT, fill=tk.X, expand=1)
        buttonBox.pack(fill=tk.X)

        self.history = MacroCommand()
        self.canvas = DrawCanvas(self, 400, 400, self.history)
        self.canvas.pack()

        self.canvas.bind("<B1-Motion>", self.mouseDragged)

    def onClearButtonClicked(self):
        self.history.clear()
        self.canvas.init();
        self.canvas.repaint()

    def mouseDragged(self, event):
        cmd = DrawCommand(self.canvas, event)
        self.history.append(cmd)
        cmd.execute()

    def onRedButtonClicked(self):
        cmd = ColorCommand(self.canvas, "red");  
        self.history.append(cmd)
        cmd.execute()

    def onGreenButtonClicked(self):
        cmd = ColorCommand(self.canvas, "green");
        self.history.append(cmd)
        cmd.execute()

    def onBlueButtonClicked(self):
        cmd = ColorCommand(self.canvas, "blue");
        self.history.append(cmd)
        cmd.execute()

