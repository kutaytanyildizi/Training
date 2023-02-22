#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_
#include "Account.h"

class SavingsAccount: public Account
{
private:
    friend ostream &operator<<(ostream &os, const SavingsAccount &account);
    static constexpr const char *defName = "Unnamed Savings Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 3.0;

protected:
    double intRate;

public:
    SavingsAccount(string name = defName, double balance = defBalance, double intRate = defIntRate);
    bool deposit(double amount);
};

#endif