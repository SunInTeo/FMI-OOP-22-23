#pragma once
#include "Book.hpp"

class Library
{
private:
    Book **m_books;
    size_t m_sizeTaken;
    size_t m_capacity;
    size_t m_numOfBooks;

public:
    Library() = delete;
    Library(size_t capacity);
    ~Library();

    bool addNewBook(Book &book);                     // - добавя нова книга към библиотеката;
                                                     // връща истина/лъжа в зависимост от това дали горните изисквания са спазени
                                                     // (бонус: направете функцията да е void и хвърлете подходящо изключение при неуспех)
    void removeBook(const char *ISBN);               // - премахва книга от библиотеката по даден ISBN;
                                                     // ако такава не съществува, да не се прави нищо
    void clear();                                    // - премахва всички книги от библиотеката
    bool empty() const;                              // - проверява дали в библиотеката има книги
    std::size_t size() const;                        // - връща броя книги в библиотеката
    const Book &operator[](std::size_t index) const; //  - връща книгата на позиция index;
                                                     // в debug режим assert-вайте, че индексът е коректен
                                                     // (бонус: при невалиден индекс, хвърлете подходящо изключение)
    const Book *find(const char *ISBN) const;        // - търси книга от библиотеката по даден ISBN;
                                                     // ако такава не съществува, да се върне nullptr
};