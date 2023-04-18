#include "MyString.hpp"

void MyString::copy(const MyString &other)
{
    char *buffer = new char[strlen(other.string) + 1];
    strcpy(buffer, other.string);
    string = buffer;
    length = other.length;
}

MyString::MyString()
    : length(0) {}

MyString::MyString(const char *string)
{
    length = strlen(string);
    this->string = new char[length + 1];
    strcpy(this->string, string);
}

MyString::MyString(const MyString &other)
{
    copy(other);
}

MyString::~MyString()
{
    if (string)
    {
        delete[] string;
    }
    length = 0;
}

MyString &MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        copy(other);
    }

    return *this;
}

char &MyString::front()
{
    return string[0];
}

const char &MyString::front() const
{
    return string[0];
}

char &MyString::back()
{
    return string[length - 1];
}

const char &MyString::back() const
{
    return string[length - 1];
}

char &MyString::operator[](std::size_t index)
{
    assert(index <= length && "Position should be lesser than length");
    return string[index];
}

const char &MyString::operator[](std::size_t index) const
{
    assert(index <= length && "Position should be lesser than length");
    return string[index];
}
