#ifndef _ACCOUNTUTIL_H_
#define _ACCOUNTUTIL_H_
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"

void display(const vector<Account> &accounts);
void deposit(vector<Account> &accounts, double amount);
void withdraw(vector<Account> &accounts, double amount);

void display(const vector<SavingsAccount> &accounts);
void deposit(vector<SavingsAccount> &accounts, double amount);
void withdraw(vector<SavingsAccount> &accounts, double amount);

#endif