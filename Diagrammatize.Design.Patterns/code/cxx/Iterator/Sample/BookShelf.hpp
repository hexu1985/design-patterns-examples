#pragma once

#include "Book.hpp"

class BookShelf;

class BookShelfIterator {
private:
    BookShelf* bookShelf;
    int index=0;

public:
    BookShelfIterator(BookShelf* bookShelf_, int index_): bookShelf(bookShelf_), index(index_)
    {}

    Book* operator*() const;

    BookShelfIterator& operator++();    // prefix increment

    BookShelfIterator operator++(int);  // postfix increment

    bool operator==(const BookShelfIterator& other) const
    {
        return (bookShelf == other.bookShelf && index == other.index);
    }

    bool operator!=(const BookShelfIterator& other) const
    {
        return !(*this == other);
    }
};

class BookShelf {
private:
    Book** books=nullptr;
    int last=0;

public:
    BookShelf(int maxsize) {
        books = new Book*[maxsize];
    }

    Book* getBookAt(int index) {
        return books[index];
    }

    void appendBook(Book* book) {
        books[last] = book;
        last++;
    }

    int getLength() {
        return last;
    }

    BookShelfIterator begin() {
        return BookShelfIterator(this, 0); 
    }

    BookShelfIterator end() {
        return BookShelfIterator(this, last); 
    }
};

inline
Book* BookShelfIterator::operator*() const {
    return bookShelf->getBookAt(index);
}

inline
BookShelfIterator& BookShelfIterator::operator++() {
    index += 1;
    return *this;
}

inline
BookShelfIterator BookShelfIterator::operator++(int) {
    BookShelfIterator tmp(*this);
    index += 1;
    return tmp;
}
