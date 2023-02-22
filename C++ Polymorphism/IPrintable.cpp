#include "IPrintable.h"

ostream& operator<<(ostream& os, const IPrintable& obj)
{
    obj.print(os);
    return os;
}