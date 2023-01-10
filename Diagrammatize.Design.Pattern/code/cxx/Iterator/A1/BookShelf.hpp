#pragma once

#include <vector>

#include "Book.hpp"

using BookShelfIterator = std::vector<Book*>::iterator;

class BookShelf {
private:
    std::vector<Book*> books;

public:
    BookShelf(int maxsize) {
        books.reserve(maxsize);
    }

    Book* getBookAt(int index) {
        return books[index];
    }

    void appendBook(Book* book) {
        books.push_back(book);
    }

    int getLength() {
        return books.size();
    }

    BookShelfIterator begin() {
        return books.begin();
    }

    BookShelfIterator end() {
        return books.end();
    }
};

