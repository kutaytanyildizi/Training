#ifndef _SAVINGS_H_
#define _SAVINGS_H_
#include <iostream>
#include <string>
#include "Account.h"

class Savings : public Account
{
private:
    static constexpr const char* defName = "Unnamed Savings Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;

protected:
    double intRate;

public:
    Savings(string name = defName, double balance = defBalance, double intRate = defIntRate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(ostream& os) const override;
    virtual ~Savings() = default;
};

#endif 