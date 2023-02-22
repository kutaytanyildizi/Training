#ifndef _MYSTRING_H_
#define _MYSTRING_H_

using namespace std;

class MyString
{ 
private:
    char *str;
    friend ostream &operator<<(ostream &os, const MyString &rhs);
    friend istream &operator>>(istream &is, MyString &rhs);

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &oth);
    MyString(MyString &&oth);
    ~MyString();
    MyString &operator=(const MyString &rhs);
    MyString &operator=(MyString &&rhs);
    void display();
    int getLength() const;
    const char *getStr() const;
};

#endif