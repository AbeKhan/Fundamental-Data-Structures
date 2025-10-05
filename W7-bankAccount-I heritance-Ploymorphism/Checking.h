#pragma once
#include "Account.h"

class Checking : public Account
{
private:
    static double overdraftFee;
    static double overdraftLimit;

public:
    Checking(string, double);
    ~Checking();

    virtual void withdraw(double) override;
};