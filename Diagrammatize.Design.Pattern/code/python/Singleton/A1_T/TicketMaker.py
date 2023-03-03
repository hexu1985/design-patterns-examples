
import threading
from Singleton import SingletonType

class TicketMaker(metaclass=SingletonType):
    _singleton = None

    def __init__(self):
        self.ticket = 1000
        self.lock = threading.Lock()

    def getNextTicketNumber(self):
        with self.lock:
            self.ticket += 1
            return self.ticket

    @staticmethod
    def getInstance():
        return TicketMaker()

