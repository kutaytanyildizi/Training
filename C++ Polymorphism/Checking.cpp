#include "Checking.h"

Checking::Checking(string name, double balance)
{
    this->name = name;
    this->balance = balance;
}

bool Checking::withdraw(double amount)
{
    amount += defFee;
    return Account::withdraw(amount);
}

bool Checking::deposit(double amount)
{
    return Account::deposit(amount);
}

void Checking::print(ostream& os) const
{
    os << "[Checking Account: " << name << " : " << balance << "]";
}
