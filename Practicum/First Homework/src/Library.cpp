#include "Library.hpp"

Library::Library(size_t capacity)
{
    m_sizeTaken = 0;
    m_capacity = capacity;
    m_numOfBooks = 0;
    m_books = new Book *[capacity];
}

Library::~Library()
{
    clear();
}

void Library::addNewBook(Book &book)
{
    if (book.space() + m_sizeTaken > m_capacity)
        throw std::invalid_argument("Not enough space for this book");

    bool bookExists = false;
    for (size_t i = 0; i < m_numOfBooks; ++i)
    {
        if (strcmp(m_books[i]->ISBN(), book.ISBN()) == 0)
        {
            bookExists = true;
        }
    }
    if (bookExists)
        throw std::invalid_argument("Book already in library");

    m_books[m_numOfBooks++] = &book;
    m_sizeTaken += book.space();
}

void Library::removeBook(const char *ISBN)
{
    for (size_t i = 0; i < m_numOfBooks; ++i)
    {
        if (strcmp(m_books[i]->ISBN(), ISBN) == 0)
        {
            m_books[i] = nullptr;
            m_numOfBooks--;
            return;
        }
    }
    /*for (size_t i = 0; i < m_numOfBooks; ++i)
    {
        if (strcmp(m_books[i]->ISBN(), ISBN) == 0)
        {
            for (size_t j = i; j < m_numOfBooks - 1; ++j)
            {
                m_books[j] = m_books[j + 1];
            }
            m_numOfBooks--;
            return;
        }
    }*/
}

void Library::clear()
{
    for (int i = 0; i < m_numOfBooks; ++i)
    {
        m_books[i] = nullptr;
    }
    m_numOfBooks = 0;
}

bool Library::empty() const
{
    return m_numOfBooks == 0;
}

std::size_t Library::size() const
{
    return m_numOfBooks;
}

const Book &Library::operator[](std::size_t index) const
{
    assert(index >= 0 && index < m_numOfBooks);
    return *m_books[index];
}

const Book *Library::find(const char *ISBN) const
{
    for (size_t i = 0; i < m_sizeTaken; ++i)
    {
        if (strcmp(m_books[i]->ISBN(), ISBN) == 0)
        {
            return m_books[i];
        }
    }
    return nullptr;
}