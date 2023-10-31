from PrinterProxy import PrinterProxy

def main():
    p = PrinterProxy("Alice")
    print("现在的名字是" + p.getPrinterName() + "。")
    p.setPrinterName("Bob")
    print("现在的名字是" + p.getPrinterName() + "。")
    p.print("Hello, world.")

if __name__ == "__main__":
    main()
