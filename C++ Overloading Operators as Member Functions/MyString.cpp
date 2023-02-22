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

MyString &MyString::operator-()
{
    char *buff = new char[strlen(str)+1];
    strcpy(buff, str);

    for(size_t i=0; i<strlen(buff); i++)
    {
        buff[i] = tolower(buff[i]);
    }

    str = nullptr;
    str = buff;
    buff = nullptr;

    return *this;
}

MyString MyString::operator+(const MyString &rhs) const
{
    size_t tempSize = strlen(str) + strlen(rhs.str) + 1;
    char *temp = new char[tempSize];
    strcpy(temp, str);
    strcat(temp, rhs.str);
    MyString buff(temp);
    delete [] temp;
    return buff;
}

bool MyString::operator==(const MyString &rhs) const
{
    if(strcmp(str,rhs.str) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
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