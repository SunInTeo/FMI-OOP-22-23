#include "LibraryAllocator.hpp"

std::size_t LibraryAllocator::getIndexOf(const Book &book)
{
    for (int i = 0; i < booksCount; i++)
    {
        if (m_books[i] == &book)
        {
            return i;
        }
    }
    return -1;
}

LibraryAllocator::~LibraryAllocator()
{
    cleanAll();
}

LibraryAllocator::LibraryAllocator(std::size_t size)
{
    lib = new Library(size);
    m_books = new Book *[size];
    booksCount = 0;
}

Book &LibraryAllocator::createNewBook(const MyString &ISBN, const MyString &title, const MyString &author, std::size_t space)
{
    Book *book = new Book(ISBN, title, author, space);
    m_books[booksCount] = book;
    booksCount++;
    return *book;
}

void LibraryAllocator::addBookToLibrary(Book &book)
{
    lib->addNewBook(book);
}

void LibraryAllocator::removeBookFromLibrary(Book &book)
{
    lib->removeBook(book.ISBN());
}

void LibraryAllocator::removeBookFromLibrary(const MyString &ISBN)
{
    lib->removeBook(ISBN.c_str());
}

const Book *LibraryAllocator::getBook(const MyString &ISBN) const
{
    return lib->find(ISBN.c_str());
}

void LibraryAllocator::eraseBook(const MyString &ISBN)
{
    std::size_t index = getIndexOf(*getBook(ISBN));
    delete m_books[index];
    m_books[index] = nullptr;
}

void LibraryAllocator::cleanAll()
{
    for (int i = 0; i < booksCount; i++)
    {
        delete m_books[i];
    }
    delete[] m_books;
    booksCount = 0;
    m_books = new Book *[booksCount];
}

void LibraryAllocator::cleanLibrary()
{
    lib->clear();
}

const void LibraryAllocator::printAll() const
{
    for (int i = 0; i < booksCount; i++)
    {
        if (m_books[i] != nullptr)
        {
            m_books[i]->print();
        }
    }
}

const void LibraryAllocator::printLibrary() const
{
    lib->print();
}

std::size_t LibraryAllocator::allBooksCount()
{
    return booksCount;
}

std::size_t LibraryAllocator::booksInLibraryCount()
{
    return lib->size();
}