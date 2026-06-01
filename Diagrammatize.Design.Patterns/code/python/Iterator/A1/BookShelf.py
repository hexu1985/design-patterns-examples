
class BookShelf:
    def __init__(self):
        self.books = []

    def getBookAt(self, index):
        return self.books[index]

    def appendBook(self, book):
        self.books.append(book)

    def getLength(self):
        return len(self.books)

    def __iter__(self):
        return iter(self.books)

