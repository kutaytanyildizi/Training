#include "MyString.h"
#include <cstring>
#include <iostream>

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
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
} 

MyString::MyString(const MyString &source)
{
    str = nullptr;
    str = new char[strlen(source.str) + 1];
    strcpy(source.str, str);
}

MyString::MyString(MyString &&source)
{
    str = source.str;
    source.str = nullptr;
}

MyString::~MyString()
{
    delete [] str;
}

MyString &MyString::operator=(const MyString &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }

    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

MyString &MyString::operator=(MyString &&rhs)
{
    if(this == &rhs)
    {
        return *this;
    }

    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    rhs.str = nullptr;
    return *this;
}

void MyString::display() const
{
    cout << str << ": " << getLenght() <<endl;
}

int MyString::getLenght() const
{
    return strlen(this->str);
}

const char* MyString::getStr() const
{
    return str;
}

MyString operator-(const MyString &rhs)
{
    size_t buff = strlen(rhs.str) + 1;
    char *temp = new char[buff];
    strcpy(temp, rhs.str);
    for(size_t i=0; i<buff; i++)
    {
        temp[i] = tolower(temp[i]);
    }
    MyString ret(temp);
    delete [] temp;
    return ret;
}

bool operator==(const MyString &lhs, const MyString &rhs)
{
    if(strcmp(lhs.str, rhs.str))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool operator!=(const MyString &lhs, const MyString &rhs)
{
    if(strcmp(lhs.str, rhs.str))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<(const MyString &lhs, const MyString &rhs)
{   
    if(strcmp(lhs.str, rhs.str) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(const MyString &lhs, const MyString &rhs)
{
    if(strcmp(lhs.str, rhs.str) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
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

MyString &operator+=(MyString &lhs, const MyString &rhs)
{
    size_t buff = strlen(lhs.str) + strlen(rhs.str) + 1;
    char *temp = new char[strlen(lhs.str)];
    strcpy(temp, lhs.str);
    delete [] lhs.str;
    lhs.str = new char[buff];
    strcpy(lhs.str, temp);
    strcat(lhs.str, rhs.str);
    delete [] temp;
    return lhs;
}

MyString operator*(const MyString &lhs,int num)
{
    char *temp = new char[strlen(lhs.getStr())*num];
    for(int i=0; i<num; i++)
    {
        strcat(temp, lhs.getStr());
    }

    MyString ret(temp);
    delete [] temp;
    return ret;
}

MyString &operator*=(MyString &lhs, int num)
{
    lhs = lhs * num;
    return lhs;
}


