#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "IPrintable.h"
#include <iostream>
#include <string>

using namespace std;

class Account : public IPrintable
{
private:
    static constexpr const char* defName = "Unnamed Account";
    static constexpr double defBalance = 0.0;

protected:
    string name;
    double balance;

public:
    Account(string name = defName, double balance = defBalance);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void print(ostream& os) const override;
    virtual ~Account() = default;
};

#endif