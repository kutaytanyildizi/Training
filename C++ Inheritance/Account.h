#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    friend ostream &operator<<(ostream &os, const Account &account);
    static constexpr const char *defName = "Unnamed Account";
    static constexpr double defBalance = 0.0;

protected:
    string name;
    double balance;

public:
    Account(string name = defName, double balance = defBalance);
    bool deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
};

#endif