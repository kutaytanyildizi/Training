#include <iostream>
#include "AccountUtil.h"

void display(const vector<Account> &accounts)
{
    cout << "-----Accounts-----" << endl;
    for(const Account &acc: accounts)
    {
        cout << acc << endl;
    }
}

void deposit(vector<Account> &accounts, double amount)
{
    cout << "-----Depositing to Accounts-----" << endl;
    for(Account &acc: accounts)
    {
        if(acc.deposit(amount))
        {
            cout << "Deposited " << amount << " to " << acc << endl;
        }
        else
        {
            cout << "Failed Deposit of " << amount << " to " << acc << endl;
        }
    }
}

void withdraw(vector<Account> &accounts, double amount)
{
    cout << "-----Withdrawing from Accounts-----" << endl;
    for(Account &acc: accounts)
    {
        if(acc.withdraw(amount))
        {
            cout << "Withdrew " << amount << " from " << acc << endl;
        }
        else
        {
            cout << "Failed Withdrew of " << amount << " from " << acc << endl;
        }
    }
}

void display(const vector<SavingsAccount> &accounts)
{
    cout << "-----Savings Accounts-----" << endl;
    for(const SavingsAccount &acc: accounts)
    {
        cout << acc << endl;
    }
}

void deposit(vector<SavingsAccount> &accounts, double amount)
{
    cout << "-----Depositing to Savings Accounts-----" << endl;
    for(SavingsAccount &acc: accounts)
    {
        if(acc.deposit(amount))
        {
            cout << "Deposited " << amount << " to " << acc << endl;
        }
        else
        {
            cout << "Failed Deposit of " << amount << " to " << acc << endl;
        }
    }
}

void withdraw(vector<SavingsAccount> &accounts, double amount)
{
    cout << "-----Withdrawing from Savings Accounts-----" << endl;
    for(SavingsAccount &acc: accounts)
    {
        if(acc.withdraw(amount))
        {
            cout << "Withdrew " << amount << " from " << acc << endl;
        }
        else
        {
            cout << "Failed Withdrew of " << amount << " from " << acc << endl;
        }
    }
}