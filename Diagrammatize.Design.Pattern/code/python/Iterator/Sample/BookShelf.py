
class BookShelfIterator: 
    def __init__(self, bookShelf, index):
        self.bookShelf = bookShelf
        self.index = index

    def __iter__(self):
        pass

    def __next__(self):
        if self.index < self.bookShelf.getLength():
            book = self.bookShelf.getBookAt(self.index)
            self.index += 1
            return book
        else:
            raise StopIteration()

class BookShelf:
    def __init__(self, maxsize):
        self.books = [None] * maxsize
        self.last = 0

    def getBookAt(self, index):
        return self.books[index]

    def appendBook(self, book):
        self.books[self.last] = book
        self.last += 1

    def getLength(self):
        return self.last

    def __iter__(self):
        return BookShelfIterator(self, 0)
