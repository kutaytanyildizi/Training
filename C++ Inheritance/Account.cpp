#include "Account.h"

Account::Account(string name, double balance)
{
    this->name = name;
    this->balance = balance;
}

bool Account::deposit(double amount)
{
    if(amount < 0)
    {
        cout << "Invalid amount." << endl;
        return false;
    }
    balance = balance + amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if(amount > balance)
    {
        cout << "There is no enough money." << endl;
        return false;
    }
    balance = balance - amount;
    return true;
}

ostream &operator<<(ostream &os, const Account &account)
{
    os << "Account Owner: " << account.name << " || Account Balance: " << account.balance;
    return os;
}

double Account::getBalance() const
{
    return balance;
}