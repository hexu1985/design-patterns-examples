from SortAndPrint import SortAndPrint
from QuickSorter import QuickSorter

def main():
    data = [
        "Dumpty", "Bowman", "Carroll", "Elfland", "Alice",
        ]
    sap = SortAndPrint(data, QuickSorter())
    sap.execute()

if __name__ == "__main__":
    main()
