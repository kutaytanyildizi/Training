#ifndef _CHECKING_H_
#define _CHECKING_H_
#include <iostream>
#include <string>
#include "Account.h"

class Checking : public Account
{
private:
    static constexpr const char* defName = "Unnamed Checking Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defFee = 1.5;

public:
    Checking(string name = defName, double balance = defBalance);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(ostream& os) const override;
    virtual ~Checking() = default;
};

#endif