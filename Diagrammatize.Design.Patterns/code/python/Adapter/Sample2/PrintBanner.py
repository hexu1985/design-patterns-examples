from Banner import Banner
from Print import Print

class PrintBanner(Print):
    def __init__(self, string):
        self.banner = Banner(string)

    def printWeak(self):
        self.banner.showWithParen()

    def printStrong(self):
        self.banner.showWithAster()
