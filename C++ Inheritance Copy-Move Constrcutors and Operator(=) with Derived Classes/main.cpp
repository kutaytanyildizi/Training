#include <iostream>

using namespace std;

class Base
{
private:
    int value;

public:
    Base()
    {
        value = 0;
        cout << "Base no-args constructor." << endl;
    }

    Base(int x)
    {
        value = x;
        cout << "Base int constructor." << endl;
    }

    Base(const Base &oth)
    {
        value = oth.value;
        cout << "Base copy constructor." << endl;
    }

    Base &operator=(const Base &rhs)
    {
        cout << "Base operator (=)." << endl;
        if(this == &rhs)
        {
            return *this;
        }

        value = rhs.value;
        return *this;
    }

    ~Base()
    {
        cout << "Base destructor." << endl;
    }
};

class Derived: public Base
{
private:
    int doubledValue;

public:
    Derived()
    {
        Base{};
        cout << "Derived no-args constructor." << endl;
    }

    Derived(int x)
    {
        Base{x};
        doubledValue = 2 * x;
        cout << "Derived int constructor." << endl;
    }

    Derived(const Derived &oth)
    {
        Base{oth};
        doubledValue = oth.doubledValue;
        cout << "Derived copy constructor." << endl;
    }

    Derived &operator=(const Derived &rhs)
    {
        cout << "Derived operator(=)." << endl;
        if(this == &rhs)
        {
            return *this;
        }

        Base::operator=(rhs);
        doubledValue = rhs.doubledValue;
        return *this;
    }

    ~Derived()
    {
        cout << "Derived destructor." << endl;
    }
};

int main()
{
    Base B(100);
    Base A(B);
    B = A;

    Derived D(100);
    Derived E(D);
    D = E;
    
    return 0;

}