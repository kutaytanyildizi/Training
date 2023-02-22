#include "Trust.h"

Trust::Trust(string name, double balance, double intRate)
{
    this->name = name;
    this->balance = balance;
    this->intRate = intRate;
    this->numWithdrawals = 0;
}

bool Trust::deposit(double amount)
{
    if (amount > 5000)
    {
        amount += bonusAmount;
        return Account::deposit(amount);
    }
    else
    {
        return Account::deposit(amount);
    }
}

bool Trust::withdraw(double amount)
{
    if (amount > (balance * maxWithdrawPercent))
    {
        cout << "You can withdraw maximum %20 of your account balance." << endl;
        return false;
    }
    else
    {
        numWithdrawals++;
        return Savings::withdraw(amount);
    }
}

void Trust::print(ostream& os) const
{
    os << "[Trust Account: " << name << " : " << balance << " : " << intRate << "% : Withdrawals: " << numWithdrawals << "]";
}
