#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(string name, double balance, double intRate)
{
    this->name = name;
    this->balance = balance;
    this->intRate = intRate;
}

bool SavingsAccount::deposit(double amount)
{
    amount = amount + (amount * intRate / 100);
    return Account::deposit(amount);
}

ostream &operator<<(ostream &os, const SavingsAccount &account)
{
    os << "Savings Account Owner: " << account.name << " || Account balance: " << account.balance << " || Interest Rate: " << account.intRate;
    return os;
}

