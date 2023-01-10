#include <iostream>

#include "BookShelf.hpp"

int main() {
    BookShelf bookShelf(4);
    bookShelf.appendBook(new Book("Around the World in 80 Days"));
    bookShelf.appendBook(new Book("Bible"));
    bookShelf.appendBook(new Book("Cinderella"));
    bookShelf.appendBook(new Book("Daddy-Long-Legs"));
    bookShelf.appendBook(new Book("East of Eden"));
    bookShelf.appendBook(new Book("Frankenstein"));
    bookShelf.appendBook(new Book("Gulliver's Travels"));
    bookShelf.appendBook(new Book("Hamlet"));
    for (auto book : bookShelf) {
        std::cout << book->getName() << std::endl;
    }
}
