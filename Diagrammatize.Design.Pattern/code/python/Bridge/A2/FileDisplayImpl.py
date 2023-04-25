from DisplayImpl import DisplayImpl

class FileDisplayImpl(DisplayImpl):
    def __init__(self, filename):
        self.filename = filename
        self.reader = None

    def rawOpen(self):
        self.reader = open(self.filename, "r")
        print("=-=-=-=-=-= " + self.filename + " =-=-=-=-=-=")

    def rawPrint(self):
        self.reader.seek(0, 0)
        for line in self.reader:
            print("> " + line)

    def rawClose(self):
        print("=-=-=-=-=-= ")
        self.reader.close()
