#include "MyString.cpp"
#include <iostream>

int main()
{
    MyString kutay("Kutay");
    kutay.display();
    kutay = -kutay;
    kutay.display();

    MyString deniz("DENIZ");
    deniz.display();
    deniz = -deniz;
    deniz.display();

    cout << (kutay == deniz) << endl;
    
    deniz = kutay;

    cout << (kutay == deniz) << endl;

    deniz = "deniz";

    MyString result = kutay + " " + deniz;
    result.display();

    return 0;
}