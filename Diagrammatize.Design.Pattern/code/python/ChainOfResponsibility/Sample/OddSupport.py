from Support import Support

class OddSupport(Support):
    def __init__(self, name):
        super().__init__(name)

    def resolve(self, trouble):
        if trouble.getNumber() % 2 == 1:
            return True
        else:
            return False
