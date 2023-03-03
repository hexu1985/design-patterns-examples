
import threading

class TicketMaker:
    _singleton = None

    def __init__(self):
        self.ticket = 1000
        self.lock = threading.Lock()

    def getNextTicketNumber(self):
        with self.lock:
            self.ticket += 1
            return self.ticket

    @classmethod
    def getInstance(cls):
        if not cls._singleton:
            cls._singleton = cls()
        return cls._singleton

