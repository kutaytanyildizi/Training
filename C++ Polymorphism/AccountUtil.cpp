#include <iostream>
#include "AccountUtil.h"

void display(const vector<Account*>& accounts)
{
	cout << "-----Accounts-----" << endl;
	for(const auto it : accounts)
	{
		cout << *it << endl;
	}
}

void deposit(vector<Account*>& accounts, double amount)
{
	cout << "-----Depositing to Accounts-----" << endl;
	for (auto it : accounts)
	{
		if (it->deposit(amount))
		{
			cout << "Deposited " << amount << " to " << *it << endl;
		}
		else
		{
			cout << "Failed Deposit of " << amount << " to " << *it << endl;
		}
	}
}

void withdraw(vector<Account*>& accounts, double amount)
{
	cout << "-----Withdrawing from Accounts-----" << endl;
	for(auto it : accounts)
	{
		if(it->withdraw(amount))
		{
			cout << "Withdrew " << amount << " from " << *it << endl;
		}
		else
		{
			cout << "Failed Withdrawal of " << amount << " from " << *it << endl;
		}
	}
}
