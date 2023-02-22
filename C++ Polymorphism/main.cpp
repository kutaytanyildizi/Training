#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "Trust.h"
#include "AccountUtil.h"

int main()
{
    Checking frank{ "Frank", 5000 };
    cout << frank << endl;

    Account* trust = new Trust("James");
    cout << *trust << endl;

    Account* p1 = new Checking("Larry", 10000);
    Account* p2 = new Savings("Moe", 1000);
    Account* p3 = new Trust("Curly");

    std::vector<Account*> accounts{ p1,p2,p3 };

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    display(accounts);

    delete p1;
    delete p2;
    delete p3;
    return 0;
}