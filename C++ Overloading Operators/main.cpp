#include "MyString.cpp"

int main()
{
    MyString kutay;
    MyString deniz;

    kutay = "Kutay";
    deniz = "Deniz";

    kutay.display();
    deniz.display();

    deniz = -deniz;
    deniz.display();

    kutay += deniz;
    kutay.display();

    kutay = kutay*3;
    kutay.display();

    kutay *= 2;
    kutay.display();
}