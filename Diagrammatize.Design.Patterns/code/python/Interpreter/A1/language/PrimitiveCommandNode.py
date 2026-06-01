
from .Node import Node
from .ParseException import ParseException

# <primitive command> ::= go | right | left
class PrimitiveCommandNode(Node):
    def __init__(self):
        super().__init__()
        self.name = None
        self.executor = None
    
    def parse(self, context):
        self.name = context.currentToken()
        context.skipToken(self.name)
        self.executor = context.createExecutor(self.name)
    
    def execute(self):
        if self.executor is None:
            raise ExecuteException(f"{self.name}: is not defined")
        else:
            self.executor.execute()
    
    def __str__(self):
        return self.name
