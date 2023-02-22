#include "MyString.cpp"
#include <iostream>

using namespace std;

int main()
{
    MyString kutay;
    MyString deniz;

    cout << "Enter your name please: ";
    cin >> kutay;

    cout << "Enter your name please: "; 
    cin >> deniz;

    cout << "Your names are " << kutay << " and " << deniz << endl;
    
    return 0;
}