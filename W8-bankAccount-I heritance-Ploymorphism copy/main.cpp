#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"

using namespace std;

int main()
{
    // Account a1("Grace Park", 1000);
    // cout << "Current balance : " << a1.getBalance() << endl;
    // a1.withdraw(500);
    // cout << "current balance after withdraw(500): " << a1.getBalance() << endl;
    // a1.deposit(1500);
    // cout << "current balance after withdraw(1500): " << a1.getBalance() << endl;

    // Savings s1("Abraham Khan", 1000, 0.01); //
    // s1.withdraw(500);
    // cout << "remaining balance after withdraw(500) : " << s1.getBalance();

    // Checking s1("Abraham Khan", 1000); //
    // s1.withdraw(1300);
    // cout << "remaining balance after withdraw(1300) : " << s1.getBalance();

    // 1. pointer to a base class
    Account *p[2];

    // 2. the pointer points to an obbject of a child class
    // int i = 0;

    for (int i = 0; i < 2; i++)
    {

        cout << "Enter a type of accont to create (0 for Checking, 1 for Saving): " << endl;
        unsigned short accountType;
        cin >> accountType;
        if (accountType == 0)
            p[i] = new Checking("GP2", 1000);
        else
            p[i] = new Savings("GP", 1000, 0.1);
    }

    // 3. use the pointer to call a virtual defined in the base
    //    which withdraw is called?
    //    --> the withdraw of the class of the objec the pointer points to
    /* pointer to the base*/ p[0]->withdraw(500); // static binding/early binding            If not  late binding/dynamic binding (This happens with virtual functions)
    p[1]->withdraw(1500);

    return 0;
}