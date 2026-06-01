
class Triple:
    _triple = None

    def __init__(self, id_):
        print("The instance " + str(id_) + " is created.");
        self.id = id_ 

    def __str__(self):
        return "[Triple id=" + str(self.id) + "]";

    @classmethod
    def getInstance(cls, id_):
        if not cls._triple:
            cls._triple = [Triple(0), Triple(1), Triple(2)]
        return cls._triple[id_]
