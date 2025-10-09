#pragma once

#include <iostream>
#include <string>

using namespace std;

class Account //abstract class: a class with a pure virtual function
              //limitation: no object of this class can be created
              //when to define an abstract class: Whenever we need need a generic "boilerplate?" format for other classes. Prevents repeated code.
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
    virtual void withdraw(double) = 0;  //pure virtual function
                    //  = 0; --> Account class does not define withdraw
                    // 
    void deposit(double);
};