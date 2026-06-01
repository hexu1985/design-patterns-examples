from Border import Border

class UpDownBorder(Border):
    def __init__(self, display, ch):
        super().__init__(display)
        self.borderChar = ch

    def getColumns(self):
        return self.display.getColumns()

    def getRows(self):
        return 1 + self.display.getRows() + 1

    def getRowText(self, row):
        if row == 0 or row == self.getRows() - 1:
            return self.makeLine(self.borderChar, self.getColumns())
        else:
            return self.display.getRowText(row-1)

    def makeLine(self, ch, count):
        return str(ch)*count

