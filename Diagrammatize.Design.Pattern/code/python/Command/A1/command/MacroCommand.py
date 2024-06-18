from .Command import Command

class MacroCommand(Command):
    def __init__(self):
        super().__init__()
        self.commands = list()

    def execute(self):
        for cmd in self.commands:
            cmd.execute()

    def append(self, cmd):
        if cmd != self:
            self.commands.append(cmd)

    def undo(self):
        if len(self.commands) > 0:
            self.commands.pop()

    def clear(self):
        self.commands = list()
