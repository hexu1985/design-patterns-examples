from Display import Display

class StringDisplay(Display):
    def __init__(self, string):
        self.string = string

    def getColumns(self):
        return self.getStringLen(self.string)

    def getRows(self):
        return 1

    def getRowText(self, row):
        if row == 0:
            return self.string
        else:
            return None
