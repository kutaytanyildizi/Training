#include "Account.h"

Account::Account(string name, double balance)
{
    this->name = name;
    this->balance = balance;
}

bool Account::deposit(double amount)
{
    if (amount < 0)
    {
        cout << "Invalid amount." << endl;
        return false;
    }

    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if (amount > balance)
    {
        cout << "There is not enough money." << endl;
        return false;
    }

    balance -= amount;
    return true;
}

void Account::print(ostream& os) const
{
    os << "[Account: " << name << " : " << balance << "]";
}
