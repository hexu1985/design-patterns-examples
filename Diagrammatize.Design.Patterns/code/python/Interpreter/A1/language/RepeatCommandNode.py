
from .Node import Node

# <repeat command> ::= repeat <number> <command list>
class RepeatCommandNode(Node):
    def __init__(self):
        super().__init__()
        self.number = 0
        self.commandListNode = None

    def parse(self, context):
        from .CommandListNode import CommandListNode
        context.skipToken("repeat")
        self.number = context.currentNumber()
        context.nextToken()
        self.commandListNode = CommandListNode()
        self.commandListNode.parse(context)

    def execute(self):
        for _ in range(self.number):
            self.commandListNode.execute()

    def __str__(self):
        return "[repeat {} {}]".format(self.number, self.commandListNode)
