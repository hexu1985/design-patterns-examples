from command import Command

class DrawCommand(Command):
    def __init__(self, drawable, position):
        self.drawable = drawable
        self.position = position

    def execute(self):
        self.drawable.draw(self.position.x, self.position.y)
