#include "Account.h"

unsigned long long Account::lastID = 0;

Account::Account(string username, double initialBalance) : accountHolder(username), balance(initialBalance) // to initalize an object (not create, that's the complier)
{
    cout << "Accout() : " << this << endl;
};
Account::~Account()
{
    cout << "~Accout() : " << this << endl;
};
double Account::getBalance() const
{
    return balance;
};

void Account::setBalance(double newBalance)
{
    balance = newBalance;
};

// void Account::withdraw(double amount)
// {
//     if (balance > amount)
//     {
//         balance -= amount;
//     }
//     else
//         cout << "insufficent funds" << endl;
// };
void Account::deposit(double amount)
{
    balance += amount;
};

// Account Account::operator+(double amount): create an object as a return type

Account& Account::operator+(double amount)
{
    deposit(amount);
    return *this; //*this --> return type & --> alias because the object is already in the memory
}

bool Account::operator<(const Account& rhs)
{
    return (this->balance < rhs.balance) ? true : false;
}

Account::operator double()
{
    return this->balance;
}
