
from ParseException import ParseException

class Context:
    EOL = chr(255)    # End Of Line

    def __init__(self, text):
        self.input = text
        self.p = 0
        self.c = self.input[self.p]
        self._currentToken = ''
        self.nextToken()

    def consume(self):
        self.p += 1
        if self.p >= len(self.input):
            self.c = Context.EOL
        else:
            self.c = self.input[self.p]

    def WS(self):
        while self.c in [' ', '\t', '\n', '\r']:
            self.consume()

    def isLETTER(self):
        return 'a' <= self.c <= 'z' or 'A' <= self.c <= 'Z'

    def isDIGIT(self):
        return '0' <= self.c <= '9'

    def nextToken(self):
        while (self.c != Context.EOL):
            if self.c in [' ', '\t', '\n', '\r']:
                self.WS()
            elif self.isLETTER():
                return self.NAME()
            elif self.isDIGIT():
                return self.NUMBER()
            else:
                raise ParseException("invalid charater: {}".format(self.c))

    def currentToken(self):
        return self._currentToken

    def skipToken(self, token):
        if self._currentToken != token:
            raise ParseException(
                    "Warning: {} is expected, but {} is found.".format(token, self._currentToken))

        self.nextToken()

    def currentNumber(self):
        number = 0
        try:
            number = int(self._currentToken)
        except ValueError as e:
            raise ParseException("Warning: {}".format(e))

        return number

    def NAME(self):
        self._currentToken = self.c
        self.consume()
        while self.isLETTER():
            self._currentToken += self.c
            self.consume()

        return self._currentToken

    def NUMBER(self):
        self._currentToken = self.c
        self.consume()
        while self.isDIGIT():
            self._currentToken += self.c
            self.consume()

        return self._currentToken

