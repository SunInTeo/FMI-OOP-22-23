#pragma once

#include <iostream>
#include <cstring>
#include <cassert>

using std::size_t;

class MyString
{
private:
    char *string = nullptr;
    size_t length;
    size_t bufferSize;

    void copy(const MyString &other);

public:
    MyString();
    MyString(const char *string);
    MyString(const MyString &other);
    ~MyString();

    MyString &operator=(const MyString &other);

    char &front(); // - първи елемент
    const char &front() const;

    char &back(); // - последен елемент
    const char &back() const;

    char &operator[](std::size_t index); // - елемент на позиция index
    const char &operator[](std::size_t index) const;

    const char *c_str() const;

    bool empty() const;           // - проверява дали символният низ е празен
    std::size_t size() const;     // - връща реалния размер на низа
    std::size_t capacity() const; // - връща максималния капацитет в текущия момент на низа

    void clear();            // - изчиства съдържанието на низа
    void pop_back();         // - премахва последния елемент на низа (в debug режим assert-вайте, че винаги ще има поне един елемент, бонус: хвърлете подходящо изключение)
    void push_back(char ch); // - залепя ch в края на низа

    MyString &operator+=(const MyString &other);     // - конкатенира низа other в края на текущия
    MyString operator+(const MyString &other) const; // - създава нов обект
                                                     // - конкатенация на текущия низ и other

    bool operator==(const MyString &other) const; // - проверява дали текущият низ еквивалентен лексикографски на other
    bool operator<(const MyString &other) const;  // - проверява дали текущият низ е преди other лексикографски
    bool operator<=(const MyString &other) const; // - проверява дали текущият низ е преди или еквивалентен на other лексикографски
    bool operator>(const MyString &other) const;  // - проверява дали текущият низ е след other лексикографски
    bool operator>=(const MyString &other) const; // - проверява дали текущият низ е след или еквивалентен на other лексикографски

    friend std::ostream &operator<<(std::ostream &out, const MyString &string); // - писане в поток
    friend std::istream &operator>>(std::istream &in, MyString &string);        // - четене от поток
};