#pragma once

#include "Library.hpp"

class LibraryAllocator
{
private:
    Library *lib;
    Book **m_books;
    int booksCount;

    std::size_t getIndexOf(const Book &book);

public:
    LibraryAllocator() = delete;
    ~LibraryAllocator();
    LibraryAllocator(std::size_t size);

    Book &createNewBook(const MyString &ISBN, const MyString &title, const MyString &author, std::size_t space);
    void addBookToLibrary(Book &book);
    void removeBookFromLibrary(Book &book);
    void removeBookFromLibrary(const MyString &ISBN);
    const Book *getBook(const MyString &ISBN) const;

    void eraseBook(const MyString &ISBN);

    void cleanAll();
    void cleanLibrary();

    const void printAll() const;
    const void printLibrary() const;

    std::size_t allBooksCount();
    std::size_t booksInLibraryCount();
};