from CountDisplay import CountDisplay

class IncreaseDisplay(CountDisplay):
    def __init__(self, impl, step):
        super().__init__(impl)
        self.step = step

    def increaseDisplay(self, level):
        count = 0
        for i in range(level):
            self.multiDisplay(count)
            count += self.step
