#include "Account.cpp"
#include "SavingsAccount.cpp"
#include "AccountUtil.cpp"

using namespace std;

int main()
{   
    vector<Account> accounts;
    accounts.push_back(Account());
    accounts.push_back(Account("Larry"));
    accounts.push_back(Account("Moe", 2000));
    accounts.push_back(Account("Curly", 5000));

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    vector<SavingsAccount> savAccounts;
    savAccounts.push_back(SavingsAccount());
    savAccounts.push_back(SavingsAccount("Kutay"));
    savAccounts.push_back(SavingsAccount("Deniz", 2000));
    savAccounts.push_back(SavingsAccount("Bülent", 10000, 5.0));

    display(savAccounts);
    deposit(savAccounts, 1000);
    withdraw(savAccounts, 2000);
    return 0;
}
