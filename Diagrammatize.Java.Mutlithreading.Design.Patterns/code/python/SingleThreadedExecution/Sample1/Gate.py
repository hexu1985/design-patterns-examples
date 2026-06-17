class Gate:
    def __init__(self):
        self.counter = 0
        self.name = "Nobody"
        self.address = "Nowhere"
    
    def pass_(self, name, address):
        self.counter += 1
        self.name = name
        self.address = address
        self._check()
    
    def __str__(self):
        return f"No.{self.counter}: {self.name}, {self.address}"
    
    def _check(self):
        if self.name and self.address and self.name[0] != self.address[0]:
            print(f"***** BROKEN ***** {self}")
