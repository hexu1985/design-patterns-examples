
from Node import Node

# <command> ::= <repeat command> | <primitive command>
class CommandNode(Node):
    def __init__(self):
        super().__init__()
        self.node = None

    def parse(self, context):
        from RepeatCommandNode import RepeatCommandNode
        from PrimitiveCommandNode import PrimitiveCommandNode
        if context.currentToken() == "repeat":
            self.node = RepeatCommandNode()
            self.node.parse(context)
        else:
            self.node = PrimitiveCommandNode()
            self.node.parse(context)

    def __str__(self):
        return str(self.node)
