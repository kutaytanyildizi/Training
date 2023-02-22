#include "MyString.cpp"

int main()
{
    MyString str1;
    MyString str2;

    str1 = "Hello";
    str2 = "HelloWorld";

    str1.display();
    str2.display();

    str2 = -str2;
    str2.display();

    str1 += str2;
    str1.display();

    str1 = str1*3;
    str1.display();

    str1 *= 2;
    str1.display();
}
