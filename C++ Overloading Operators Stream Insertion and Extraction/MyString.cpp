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

ostream &operator<<(ostream &os, const MyString &rhs)
{
    os << rhs.str;
    return os;
}

istream &operator>>(istream &is, MyString &rhs)
{
    char *temp = new char[1000];
    is >> temp;
    strcpy(rhs.str, temp);
    delete []temp;
    return is;
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