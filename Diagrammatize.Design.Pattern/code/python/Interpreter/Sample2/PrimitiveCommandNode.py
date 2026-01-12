
from Node import Node
from ParseException import ParseException

# <primitive command> ::= go | right | left
class PrimitiveCommandNode(Node):
    def __init__(self):
        super().__init__()
        self.name = ''

    def parse(self, context):
        self.name = context.currentToken()
        context.skipToken(self.name)
        if not self.name in ["go", "right", "left"]:
            raise ParseException("{} is undefined".format(self.name))

    def __str__(self):
        return self.name
