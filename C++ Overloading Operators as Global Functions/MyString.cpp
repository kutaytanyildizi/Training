#include <cstring>
#include <iostream>
#include "MyString.h"

using namespace std;

MyString::MyString()
{
    str = nullptr;
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char *s)
{
    str = nullptr;
    if(s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s)+1];
        strcpy(str, s);
    }
}

MyString::MyString(const MyString &oth)
{
    str = nullptr;
    str = new char[strlen(oth.str)+1];
    strcpy(str, oth.str);
}

MyString::MyString(MyString &&oth)
{
    str = oth.str;
    oth.str = nullptr;
    cout << "Move Constructor Used" << endl;
}

MyString::~MyString()
{
    delete [] str;
}

MyString &MyString::operator=(const MyString &rhs)
{
    cout << "Copy assignment" << endl;
    if(this == &rhs)
    {
        return *this;
    }

    delete [] this->str;
    str = new char[strlen(rhs.str)+1];
    strcpy(str, rhs.str);
    return *this;
}

MyString &MyString::operator=(MyString &&rhs)
{
    cout << "Move assignment" << endl;
    if(this == &rhs)
    {
        return *this;
    }

    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

bool operator==(const MyString &lhs, const MyString &rhs)
{
    if(strcmp(rhs.str, lhs.str))
    {
        return false;
    }
    else
    {
        return true;
    }
}

MyString operator-(const MyString &obj)
{
    size_t buff = strlen(obj.str) + 1;
    char *temp = new char[buff];
    strcpy(temp, obj.str);
    for(size_t i=0; i<buff; i++)
    {
        temp[i] = tolower(temp[i]);
    }

    MyString ret(temp);
    delete[] temp;
    return ret;
}

MyString operator+(const MyString &lhs, const MyString &rhs)
{
    size_t buff = strlen(lhs.str) + strlen(rhs.str) + 1;
    char *temp = new char[buff];
    strcpy(temp, lhs.str);
    strcat(temp, rhs.str);

    MyString ret(temp);
    delete [] temp;
    return ret;
}

void MyString::display()
{
    cout << str << ":" << getLength() << endl;
}

int MyString::getLength() const
{
    return strlen(str);
}

const char* MyString::getStr() const
{
    return str;
}