
import io
from Node import Node
from ParseException import ParseException

# <command list> ::= <command>* end
class CommandListNode(Node):
    def __init__(self):
        super().__init__()
        self.list = []

    def parse(self, context):
        from CommandNode import CommandNode
        while True:
            if not context.currentToken():
                raise ParseException("Missing 'end'")
            elif context.currentToken() == "end":
                context.skipToken("end")
                break
            else:
                commandNode = CommandNode()
                commandNode.parse(context)
                self.list.append(commandNode)

    def __str__(self):
        str_list = [str(token) for token in self.list]
        buffer = io.StringIO()
        buffer.write("[")
        buffer.write(" ".join(str_list))
        buffer.write("]")
        return buffer.getvalue()

