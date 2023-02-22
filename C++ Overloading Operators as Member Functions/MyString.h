#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString
{
private:
    char *str;

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &oth);
    MyString(MyString &&oth);
    ~MyString();
    MyString &operator=(const MyString &rhs);
    MyString &operator=(MyString &&rhs);
    MyString &operator-();
    MyString operator+(const MyString &rhs) const; 
    bool operator==(const MyString &rhs) const;
    void display();
    int getLength() const;
    const char *getStr() const;
};

#endif