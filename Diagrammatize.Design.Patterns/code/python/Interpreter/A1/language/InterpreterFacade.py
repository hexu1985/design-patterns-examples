
from .Executor import Executor
from .ProgramNode import ProgramNode
from .ParseException import ParseException
from .ExecuteException import ExecuteException
from .Context import Context

class InterpreterFacade(Executor):
    def __init__(self, factory):
        self._factory = factory
        self._context = None
        self._programNode = None

    def parse(self, text):
        ok = True
        self._context = Context(text)
        self._context.setExecutorFactory(self._factory)
        self._programNode = ProgramNode()

        try:
            self._programNode.parse(self._context)
            print(self._programNode)
        except ParseException as e:
            print(f"Parse error: {e}")
            ok = False

        return ok

    def execute(self):
        try:
            if self._programNode:
                self._programNode.execute()
        except ExecuteException as e:
            print(f"Execute error: {e}")
