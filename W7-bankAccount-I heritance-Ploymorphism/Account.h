#pragma once

#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    string accountHolder;
    double balance; // 8 bytes
    // long account number; long: 4 byte or 8 byte depending on OS
    unsigned long long accountNumber; // 8 bytes, increment lastID
    static unsigned long long lastID;

public:
    // Account();
    Account(string, double);
    ~Account();
    double getBalance() const;
    void setBalance(double);
    virtual void withdraw(double);
    void deposit(double);
};