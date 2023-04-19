#include "MyString.hpp"

class Book
{
private:
    MyString m_ISBN;
    MyString m_title;
    MyString m_author;
    std::size_t m_space;

    void copy(const Book &other);

public:
    Book() = delete;
    Book(const char *ISBN, const char *title, const char *author, std::size_t space); // maybe not needed
    Book(const MyString &ISBN, const MyString &title, const MyString &author, std::size_t space); 
    Book(const Book &other);
    Book &operator=(const Book &other);
    ~Book() = default;

    const char *ISBN() const; // - връща ISBN - a като C - style символен низ 
    const char *title() const; // - връща заглавието като C - style символен низ 
    const char *author() const; // - връща автора като C - style символен низ 
    std::size_t space() const; // - връща броя места, които заема на един рафт
};
