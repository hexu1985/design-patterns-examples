
class SortAndPrint:
    def __init__(self, data, sorter):
        self.data = data
        self.sorter = sorter

    def execute(self):
        self.print()
        self.sorter.sort(self.data)
        self.print()

    def print(self):
        for item in self.data:
            print("{}, ".format(item), end='')
        print()
