from Support import Support

class SpecialSupport(Support):
    def __init__(self, name, number):
        super().__init__(name)
        self.number = number

    def resolve(self, trouble):
        if trouble.getNumber() == self.number:
            return True
        else:
            return False
