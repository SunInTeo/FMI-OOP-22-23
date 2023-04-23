#include "Book.hpp"

void Book::copy(const Book &other)
{
    this->m_ISBN = other.m_ISBN;
    this->m_title = other.m_title;
    this->m_author = other.m_author;
    this->m_space = other.m_space;
}

Book::Book(const char *ISBN = nullptr, const char *title = nullptr, const char *author = nullptr, std::size_t space)
    : m_ISBN(ISBN), m_title(title), m_author(author), m_space(space)
{
}

Book::Book(const MyString &ISBN, const MyString &title, const MyString &author, std::size_t space)
    : m_ISBN(ISBN), m_title(title), m_author(author), m_space(space)
{
}

Book::Book(const Book &other)
{
    copy(other);
}

Book &Book::operator=(const Book &other)
{
    if (this != &other)
    {
        copy(other);
    }

    return *this;
}

const char *Book::ISBN() const
{
    return this->m_ISBN.c_str();
}

const char *Book::title() const
{
    return this->m_title.c_str();
}

const char *Book::author() const
{
    return this->m_author.c_str();
}

std::size_t Book::space() const
{
    return this->m_space;
}