#pragma once

#include <iostream>
#include <cstring>
#include <cassert>

class MyString
{
private:
    char *string = nullptr;
    std::size_t length;

    void copy(const MyString &other);

public:
    MyString();
    MyString(const char *string);
    MyString(const MyString &other);
    ~MyString();

    MyString &operator=(const MyString &other);

    /*
    Всеки от горепосочените методи трябва да има и аналогична константна версия.
    В debug режим assert-вайте, че употребата им винаги ще е коректна
    (ще има поне един елемент и index ще е по-малък от размера на низа).*/
    char &front(); // - първи елемент
    const char &front() const;

    char &back(); // - последен елемент
    const char &back() const;

    char &operator[](std::size_t index); // - елемент на позиция index
    const char &operator[](std::size_t index) const;
};