from Support import Support

class LimitSupport(Support):
    def __init__(self, name, limit):
        super().__init__(name)
        self.limit = limit

    def resolve(self, trouble):
        if trouble.getNumber() < self.limit:
            return True
        else:
            return False
