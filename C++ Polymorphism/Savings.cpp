#include "Savings.h"

Savings::Savings(string name, double balance, double intRate)
{
    this->name = name;
    this->balance = balance;
    this->intRate = intRate;
}

bool Savings::deposit(double amount)
{
    amount += amount * (intRate / 100);
    return Account::deposit(amount);
}

bool Savings::withdraw(double amount)
{
    return Account::withdraw(amount);
}

void Savings::print(ostream& os) const
{
    os << "[Savings Account: " << name << " : " << balance << " : " << intRate << "]";
}

