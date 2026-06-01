from Banner import Banner
from Print import Print

class PrintBanner(Banner, Print):
    def __init__(self, string):
        super().__init__(string)

    def printWeak(self):
        self.showWithParen()

    def printStrong(self):
        self.showWithAster()
