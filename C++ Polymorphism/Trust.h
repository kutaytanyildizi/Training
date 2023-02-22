#ifndef _TRUST_H_
#define _TRUST_H_
#include <iostream>
#include <string>
#include "Savings.h"

class Trust : public Savings
{
private:
    static constexpr const char* defName = "Unnamed Trust Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;
    static constexpr double bonusAmount = 50.0;
    static constexpr double bonusThresHold = 50000.0;
    static constexpr int maxWithdrawls = 3;
    static constexpr double maxWithdrawPercent = 0.2;

protected:
    int numWithdrawals;

public:
    Trust(string name = defName, double balance = defBalance, double intRate = defIntRate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(ostream& os) const override;
    virtual ~Trust() = default;
};

#endif