from Display import Display

class MultiStringDisplay(Display):
    def __init__(self):
        self.body = list()
        self.columns = 0

    def add(self, msg):
        self.body.append(msg)
        self.updateColumn(msg)

    def getColumns(self):
        return self.columns

    def getRows(self):
        return len(self.body)

    def getRowText(self, row):
        return self.body[row]

    def updateColumn(self, msg):
        if len(msg) > self.columns:
            self.columns = len(msg)

        for row in range(len(self.body)):
            fills = self.columns - len(self.body[row])
            if fills > 0:
                self.body[row] = self.body[row] + self.spaces(fills)

    def spaces(self, count):
        return ' '*count
