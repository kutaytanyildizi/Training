#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString
{
    
private:
    char *str;
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend MyString operator-(const MyString &obj);
    friend MyString operator+(const MyString &lhs, const MyString &rhs);

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