#include "MyString.cpp"
#include <iostream>

int main()
{
    MyString helloWorld("Hello World");
    MyString hello(helloWorld);
    MyString kutay("Kutay");

    helloWorld.display();
    hello.display();
    kutay.display();

    hello = kutay;
    hello.display();

    MyString deniz;
    deniz = "Deniz";
    deniz.display();

    -deniz;

    deniz.display();

    hello = kutay + " " + deniz;

    kutay = deniz;

    if(kutay==deniz)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    hello.display();


    return 0;
}