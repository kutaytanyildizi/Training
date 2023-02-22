#ifndef _MYSTRING_H_
#define _MYSTRING_H_


class MyString
{
private:
    char *str;
    friend MyString operator-(const MyString &rhs);
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend bool operator!=(const MyString &lhs, const MyString &rhs);
    friend bool operator<(const MyString &lhs, const MyString &rhs);
    friend bool operator>(const MyString &lhs, const MyString &rhs);
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
    friend MyString &operator+=(MyString &lhs, const MyString &rhs);
    friend MyString operator*(const MyString &lhs, int num);
    friend MyString &operator*=(MyString &lhs,int num);

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    MyString(MyString &&source);
    ~MyString();
    MyString &operator=(const MyString &rhs);
    MyString &operator=(MyString &&rhs);
    void display() const;
    int getLenght() const;
    const char* getStr() const;
};

#endif