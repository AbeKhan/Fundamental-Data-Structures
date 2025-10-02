#include "Account.h"

unsigned long long Account::lastID = 0;

Account::Account(string username, double initialBalance) : accountHolder(username), balance(initialBalance)
{
    cout << "Accout() : " << this << endl;
};
Account::~Account()
{
    cout << "~Accout() : " << this << endl;
};
double Account::getBalance() const {
    return balance;
};
void Account::withdraw(double amount) {
    if(balance > amount)
    {
        balance -= amount;
    }
    else
        cout << "insufficent funds" << endl;
};
void Account::deposit(double amount) {
    balance += amount;
};

