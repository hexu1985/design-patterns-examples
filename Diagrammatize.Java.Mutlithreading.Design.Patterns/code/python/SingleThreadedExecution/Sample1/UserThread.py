import threading
import time

class UserThread(threading.Thread):
    def __init__(self, gate, myname, myaddress):
        super().__init__()
        self.gate = gate
        self.myname = myname
        self.myaddress = myaddress
    
    def run(self):
        print(f"{self.myname} BEGIN")
        while True:
            self.gate.pass_(self.myname, self.myaddress)
    
