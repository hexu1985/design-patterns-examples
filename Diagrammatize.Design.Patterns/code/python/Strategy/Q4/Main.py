from SortAndPrint import SortAndPrint
from SelectionSorter import SelectionSorter

def main():
    data = [
        "Dumpty", "Bowman", "Carroll", "Elfland", "Alice",
        ]
    sap = SortAndPrint(data, SelectionSorter())
    sap.execute()

if __name__ == "__main__":
    main()
