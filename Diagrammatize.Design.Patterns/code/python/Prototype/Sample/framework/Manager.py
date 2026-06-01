
class Manager:
    def __init__(self):
        self.showcase = dict()

    def register(self, name, proto):
        self.showcase[name] = proto

    def create(self, protoname):
        p = self.showcase[protoname]
        return p.createClone()
