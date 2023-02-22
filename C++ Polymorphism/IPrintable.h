#ifndef _IPRINTABLE_H_
#define _IPRINTABLE_H_
#include <iostream>

using namespace std;

class IPrintable
{
private:
    friend ostream& operator<<(ostream& os, const IPrintable& obj);

public:
    virtual void print(ostream& os) const = 0;
    virtual ~IPrintable() = default;
};

#endif
