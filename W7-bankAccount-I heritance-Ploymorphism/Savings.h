#pragma once
#include "Account.h"

//: inheritance mechanism baseClass
// public inheritance: public in the baseClass is still public in the childClass -> public is preserved
//                     private in the baseClass --> inherited but not directly accessible by the child4
//                     Q: how does the child class initialize the private members of the base class?
//                        --> use ther constructor of the base class because it is public
//                     protected --> discussed later
// Q: what to define in the child class: additional memeber, do not repeat the inheritrf members
class Savings : public Account
{
private:
    double interestRate; // annual interest

public:
    Savings(string, double, double);
    ~Savings();
    void withdraw(double); // add the limit --> extend the inherrited feature
                           //--> only then, redefine it with the same function signature
};
