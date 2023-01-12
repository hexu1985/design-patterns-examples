from Book import Book
from BookShelf import BookShelf

def main():
    bookShelf = BookShelf(4)
    bookShelf.appendBook(Book("Around the World in 80 Days"))
    bookShelf.appendBook(Book("Bible"))
    bookShelf.appendBook(Book("Cinderella"))
    bookShelf.appendBook(Book("Daddy-Long-Legs"))
    for book in bookShelf:
        print(book.getName())

if __name__ == "__main__":
    main()
