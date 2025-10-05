#include <iostream>
#include "Checking.h"

double Checking::overdraftFee = 30.00;
double Checking::overdraftLimit = -300.00; //smallest negative balance

Checking::Checking(string name, double initialBalance) : Account(name, initialBalance)
{
    cout << "Checking() : " << this << endl;
};

Checking::~Checking()
{
    cout << "~Checking() : " << this << endl;
};

void Checking::withdraw(double amount)
{
    double currectBalance = getBalance();
    if(currectBalance - amount <= overdraftLimit)
    {
        cout << "overdraftLimit reached!" << endl;
    }
    else if (currectBalance - amount < 0)
    {
        currectBalance -= amount - overdraftFee;
        // currectBalance = currectBalance - amount - overdraftFee;
    }
    else
        currectBalance -= amount;

    setBalance(currectBalance);
    
}