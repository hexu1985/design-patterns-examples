
from Node import Node
from CommandListNode import CommandListNode

class ProgramNode(Node):
    def __init__(self):
        self.commandListNode = None

    def parse(self, context):
        context.skipToken("program")
        self.commandListNode = CommandListNode()
        self.commandListNode.parse(context)

    def __str__(self):
        return "[program {}]".format(self.commandListNode)
