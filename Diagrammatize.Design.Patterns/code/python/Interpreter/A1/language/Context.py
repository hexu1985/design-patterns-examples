
from .ParseException import ParseException
from .ExecutorFactory import ExecutorFactory

class Context(ExecutorFactory):
    def __init__(self, text):
        self._tokenizer = text.split()
        self._index = 0
        self._currentToken = None
        self._factory = None
        self.nextToken()
    
    def nextToken(self):
        if self._index < len(self._tokenizer):
            self._currentToken = self._tokenizer[self._index]
            self._index += 1
        else:
            self._currentToken = None
        return self._currentToken
    
    def currentToken(self):
        return self._currentToken
    
    def skipToken(self, token):
        if token != self._currentToken:
            raise ParseException("Warning: " + token + " is expected, but " + str(self._currentToken) + " is found.")
        self.nextToken()
    
    def currentNumber(self):
        if self._currentToken is None:
            raise ParseException("Warning: No token available")
        
        try:
            return int(self._currentToken)
        except ValueError as e:
            raise ParseException("Warning: " + str(e))

    def setExecutorFactory(self, factory):
        self._factory = factory

    def createExecutor(self, name):
        return self._factory.createExecutor(name)


