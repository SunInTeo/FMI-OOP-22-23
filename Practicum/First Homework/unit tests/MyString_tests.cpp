#include <iostream>
#include <cstring>
#include "catch2.hpp"

#include "../src/MyString.hpp"

TEST_CASE("Rule of 3")
{
    MyString str;
    REQUIRE(str.size() == 0);
    MyString str1(str);
    REQUIRE(str.size() == str1.size());
    MyString str2("test");
    REQUIRE(str2.size() == 4);
    MyString str3 = str2;
    REQUIRE(str3 == str2);
}

TEST_CASE("front() and back() functions")
{
    MyString str("void");

    SECTION("front()")
    {
        REQUIRE(str.front() == 'v');
        const char ch1 = str.front();
        REQUIRE(ch1 == 'v');
        str.front() = 'V';
    }

    SECTION("back()") {
        REQUIRE(str.back() == 'd');
        const char ch2 = str.back();
        REQUIRE(ch2 == 'd');
    }
}

TEST_CASE("[] operator")
{
    MyString str("qwerty");
    REQUIRE(str[0] == 'q');
    REQUIRE(str[3] == 'r');
    REQUIRE(str[5] == 'y');

    const char ch = str[4];
    REQUIRE(ch == 't');

    str[2] = 'E';
    REQUIRE(str[2] == 'E');
}

TEST_CASE("c_str() function")
{
    MyString str("Hello world!");
    size_t len = strlen(str.c_str());
    REQUIRE(len == str.size());
    REQUIRE(str.c_str()[len] == '\0');
}

TEST_CASE("empty(), size(), and clear() functions")
{
    SECTION("empty()")
    {
        MyString strEmpty;
        REQUIRE(strEmpty.empty());
        MyString strEmpty2("");
        REQUIRE(strEmpty2.empty());
    }

    SECTION("size() and clear()")
    {
        MyString str("test");
        REQUIRE(str.size() == 4);
        str.clear();
        REQUIRE(str.size() == 0);
    }
}

TEST_CASE("pop_back() and push_back() functions")
{
    MyString str("Hello world");

    SECTION("push_back()")
    {
        size_t oldlen = str.size();
        str.push_back('!');
        REQUIRE(str.size() == oldlen + 1);
        REQUIRE(str.back() == '!');
        REQUIRE(str == "Hello world!");
    }

    SECTION("pop_back()")
    {
        size_t oldlen = str.size();
        str.pop_back();
        REQUIRE(str.size() == oldlen - 1);
        REQUIRE(str.back() == 'd');
        REQUIRE(str == "Hello worl");
    }
}

TEST_CASE("operator+=")
{
    SECTION("operator+= (const MyString &other)") 
    {
        MyString str1("Hello world");
        str1 += "!";
        REQUIRE(str1 == "Hello world!");
    }

    SECTION("operator+= (const char *other)")
    {
        MyString str1("Hello world");
        MyString str2(" My name is George!");
        str1 += str2;
        REQUIRE(str1 == "Hello world! My name is George!");
    }
}

TEST_CASE("operator+")
{
    SECTION("operator+ (const MyString &other)")
    {
        MyString str1("Hello world");
        MyString str2("!");
        MyString str3 = str1 + str2;
        REQUIRE(str3 == "Hello world!");
    }

    SECTION("operator+ (const char *other)")
    {
        MyString str1("Hello world");
        MyString str2(" My name is George!");
        MyString str3 = str1 + str2;
        REQUIRE(str3 == "Hello world! My name is George!");
    }
}

TEST_CASE("comparisons")
{
    SECTION("operator==")
    {
        MyString str1("test1");
        MyString str2("test2");
        REQUIRE(!(str1 == str2));
        str1 = str2;
        REQUIRE(str1 == str2);
    }

    SECTION("operator<")
    {
        MyString str1("test1");
        MyString str2("test2");
        REQUIRE(str1 < str2);
        REQUIRE(!(str2 < str1));
    }

    SECTION("operator>")
    {
        MyString str1("test1");
        MyString str2("test2");
        REQUIRE(str2 > str1);
        REQUIRE(!(str1 > str2));
    }

    SECTION("operator<=")
    {
        MyString str1("test1");
        MyString str2("test2");
        REQUIRE(str1 <= str2);
        REQUIRE(!(str2 <= str1));
        str1 = str2;
        REQUIRE(str1 <= str2);
    }

    SECTION("operator>=")
    {
        MyString str1("test1");
        MyString str2("test2");
        REQUIRE(str2 >= str1);
        REQUIRE(!(str1 >= str2));
        str1 = str2;
        REQUIRE(str1 >= str2);
    }
}
