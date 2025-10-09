#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"

using namespace std;

ostream &operator<<(ostream &out, const Account &account);
istream &operator<<(istream &out, const Account &account);

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
    Account *p[5];
    // Account a -->Account : abstract class, invalid
    // Account*q = new Account;

    // 2. the pointer points to an obbject of a child class
    // int i = 0;

    for (int i = 0; i < 5; i++)
    {

        string accountHolder = "GP";
        accountHolder += to_string(i);
        cout << "Enter a type of accont to create (0 for Checking, 1 for Saving): " << endl;
        unsigned short accountType;
        cin >> accountType;
        if (accountType == 0)
        {

            p[i] = new Checking(accountHolder, 1000);
        }

        else
            p[i] = new Savings(accountHolder, 1000, 0.1);
    }

    // syntax: cout << account_obj: output stream operator, stream insertion operator
    // operator<<(cout, account_obj): --> cannot be a memeber of the Account
    //           --> binary operator --> to be a member of the Account, the left operand must be of Account type
    //           --> make it a friend so that operator<< can access the private members
    //           --> make it a free function --> call getter/setter to access the private members
    cout << ((*p[0]) + 200); // Account + 200 --> add 200 to the account 's balance

    // cout << a1 << a2; //cascaded operator
    //--> cout << a1; ---> return cout
    //  --> operator<<(cout, a1); --> return type cout ->> ostream&
    //--> cout << a2; --> operator

    // 3. use the pointer to call a virtual defined in the base
    //    which withdraw is called?
    //    --> the withdraw of the class of the objec the pointer points to
    // /* pointer to the base*/ p[0]->withdraw(500); // static binding/early binding            If not  late binding/dynamic binding (This happens with virtual functions)
    // p[1]->withdraw(1500);

    cout << (*p[0] < *p[1]);

    double current_balance = (double) (*p[2]);
            //(*p[2])->operator double()

    return 0;
}

ostream &operator<<(ostream &out, const Account &account)
{
    out << "Holder: " << account.accountHolder << endl;
    out << "Number: " <<account.accountNumber << endl;
    out << "Balance: " <<account.balance << endl;
}