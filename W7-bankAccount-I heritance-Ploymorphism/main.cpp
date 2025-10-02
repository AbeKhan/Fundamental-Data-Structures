#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
    Account a1("Grace Park", 1000);
    cout << "Current balance : " << a1.getBalance() << endl;
    a1.withdraw(500);
    cout << "current balance after withdraw(500): " << a1.getBalance() << endl;
    a1.deposit(1500);
    cout << "current balance after withdraw(1500): " << a1.getBalance() << endl;

    return 0;
}