#include "Savings.h"


//1. If a constructor of Savings does not explicitly call a constructor of Account,
//   the complier adds a code to call the default constructor of Account
Savings::Savings(string name, double initialBalance, double interestRate) : Account(name, initialBalance), 
{
    this->interestRate = interestRate;
};