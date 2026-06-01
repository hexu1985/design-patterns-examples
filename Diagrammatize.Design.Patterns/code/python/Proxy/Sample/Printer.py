import time

from Printable import Printable

class Printer(Printable):
    def __init__(self, name=""):
        self.name = name
        if self.name:
            self.heavyJob("正在生成Printer的实例(" + name + ")")
        else:
            self.heavyJob("正在生成Printer的实例")

    def setPrinterName(self, name):
        self.name = name

    def getPrinterName(self):
        return self.name

    def print(self, string):
        print("=== " + self.name + " ===")
        print(string)

    def heavyJob(self, msg):
        print(msg, end="", flush=True)
        for i in range(5):
            time.sleep(1.0)
            print(".", end="", flush=True)
        print("结束。")
