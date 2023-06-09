from Border import Border

class FullBorder(Border):
    def __init__(self, display):
        super().__init__(display)

    def getColumns(self):
        return 1 + self.display.getColumns() + 1

    def getRows(self):
        return 1 + self.display.getRows() + 1

    def getRowText(self, row):
        if row == 0:
            return "+" + self.makeLine('-', self.display.getColumns()) + "+"
        elif row == self.display.getRows() + 1:
            return "+" + self.makeLine('-', self.display.getColumns()) + "+"
        else: 
            return "|" + self.display.getRowText(row - 1) + "|"

    def makeLine(self, ch, count):
        return str(ch)*count
