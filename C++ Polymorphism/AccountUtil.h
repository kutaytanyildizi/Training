#ifndef _ACCOUNTUTIL_H_
#define _ACCOUNTUTIL_H_
#include <iostream>
#include <vector>
#include "Account.h"

void display(const vector<Account*> &accounts);
void deposit(vector<Account*>& accounts, double amount);
void withdraw(vector<Account*>& accounts, double amount);

#endif