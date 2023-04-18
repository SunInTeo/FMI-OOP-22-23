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
    clear();
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

const char *MyString::c_str() const
{
    return string;
}

bool MyString::empty() const
{
    return length == 0;
}

std::size_t MyString::size() const
{
    return length;
}

std::size_t MyString::capacity() const
{
    return length;
}

void MyString::clear()
{
    if (string)
    {
        delete[] string;
    }
    length = 0;
}

void MyString::pop_back()
{
    assert(length > 0 && "Length should be greater than 0");
    char *buffer = new char[length];
    strncpy(buffer, string, length - 1);
    buffer[length - 1] = '\0';
    delete[] string;
    string = buffer;
    length--;
}

void MyString::push_back(char ch)
{
    char *buffer = new char[length + 2];
    strcpy(buffer, string);
    buffer[length] = ch;
    buffer[length + 1] = '\0';
    delete[] string;
    string = buffer;
    length++;
}

MyString &MyString::operator+=(const MyString &other)
{
    char *buffer = new char[length + other.length + 1];
    strcpy(buffer, string);
    strcat(buffer, other.string);
    delete[] string;
    string = buffer;
    length += other.length;

    return *this;
}

MyString MyString::operator+(const MyString &other) const
{
    MyString result(*this);
    result += other;

    return result;
}

bool MyString::operator==(const MyString &other) const
{
    return strcmp(string, other.string) == 0;
}

bool MyString::operator<(const MyString &other) const
{
    return strcmp(string, other.string) < 0;
}

bool MyString::operator>(const MyString &other) const
{
    return strcmp(string, other.string) > 0;
}

bool MyString::operator<=(const MyString &other) const
{
    return !(*this > other);
}

bool MyString::operator>=(const MyString &other) const
{
    return !(*this < other);
}

std::ostream &operator<<(std::ostream &out, const MyString &str)
{
    out << str.string;
    return out;
}

std::istream &operator>>(std::istream &in, MyString &str)
{
    char buffer[1000];
    in >> buffer;
    str = MyString(buffer);
    return in;
}
