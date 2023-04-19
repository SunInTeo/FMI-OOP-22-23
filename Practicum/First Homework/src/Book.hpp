#include "MyString.hpp"

/*Реализирайте клас Book (книга), който съдържа следните полета:
Нека той има следния интерфейс:
Да НЯМА конструктор по подразбиране
Да има конструктор с параметри - Book(const char* ISBN, const char* title, const char* author, std::size_t space)
Да спазва Rule of 0/3*/
class Book
{
private:
    MyString ISBN;
    MyString title;
    MyString author;
    std::size_t space;

public:
    Book(const char *ISBN, const char *title, const char *author, std::size_t space);

    const char *ISBN() const; // - връща ISBN - a като C - style символен низ 
    const char *title() const; // - връща заглавието като C - style символен низ 
    const char *author() const; // - връща автора като C - style символен низ 
    std::size_t space() const; // - връща броя места, които заема на един рафт
};
