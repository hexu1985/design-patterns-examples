from command import Command

class ColorCommand(Command):
    def __init__(self, drawable, color):
        self.drawable = drawable
        self.color = color

    def execute(self):
        self.drawable.setColor(self.color)
