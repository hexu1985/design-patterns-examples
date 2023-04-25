from Display import Display

class CountDisplay(Display):
    def __init__(self, impl):
        super().__init__(impl)       

    def multiDisplay(self, times):
        self.open()
        for i in range(times):
            self.print()
        self.close()
