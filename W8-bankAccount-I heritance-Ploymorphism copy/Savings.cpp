#include "Savings.h"

// 1. If a constructor of Savings does not explicitly call a constructor of Account,
//    the complier adds a code to call the default constructor of Account

Savings::Savings(string name, double initialBalance, double initialRate)
    : Account(name, initialBalance), interestRate(initialRate)
{
    cout << "Savings() : " << this << endl;
};

Savings::~Savings()
{
    cout << "~Savings() : " << this << endl;
};

void Savings::withdraw(double amount)
{
    if (amount <= DARWCAP)
    {
        setBalance(getBalance() - amount);
    }
    else
        cout << "Withdraw limit reached." << endl;
};