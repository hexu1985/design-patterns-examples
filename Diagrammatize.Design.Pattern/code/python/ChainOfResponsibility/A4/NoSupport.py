from Support import Support

class NoSupport(Support):
    def __init__(self, name):
        super().__init__(name)

    def resolve(self, trouble):
        return False
