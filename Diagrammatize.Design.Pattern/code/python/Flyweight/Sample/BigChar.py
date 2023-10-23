
class BigChar:
    def __init__(self, charname):
        self.charname = charname
        try:
            reader = open("big" + charname + ".txt")
            buf = []
            for line in reader:
                buf.append(line)
            reader.close()
            self.fontdata = "".join(buf)
        except Exception as e:
            self.fontdata = charname + "?"

    def print(self):
        print(self.fontdata, end="")

