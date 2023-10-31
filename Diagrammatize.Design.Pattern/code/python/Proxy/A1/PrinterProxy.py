import threading

from Printable import Printable
from PrinterManager import PrinterManager

class PrinterProxy(Printable):
    def __init__(self, name, className):
        self.name = name
        self.className = className
        self.real = None
        self.lock = threading.Lock()

    def setPrinterName(self, name):
        with self.lock:
            if self.real is not None:
                self.real.setPrinterName(name)
            self.name = name

    def getPrinterName(self):
        return self.name

    def print(self, string):
        self.realize()
        self.real.print(string)

    def realize(self):
        with self.lock:
            if self.real is None:
                self.real = PrinterManager.newInstance(self.className)
                if self.real:
                    self.real.setPrinterName(self.name)
                else:
                    print("没有找到 " + className + " 类。")

