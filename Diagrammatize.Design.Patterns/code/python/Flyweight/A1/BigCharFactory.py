
import threading
from BigChar import BigChar

class BigCharFactory:
    singleton = None

    def __init__(self):
        self.pool = dict()
        self.lock = threading.Lock()

    @classmethod
    def getInstance(cls):
        if not cls.singleton:
            cls.singleton = cls()
        return cls.singleton

    def getBigChar(self, charname):
        with self.lock:
            bc = self.pool.get(charname)
            if bc is None:
                bc = BigChar(charname)
                self.pool[charname] = bc
            return bc



