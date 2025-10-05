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
    const double DARWCAP = 500;

public:
    Savings(string, double, double);
    ~Savings();
    // overriding: redefining an inherited virtual function
    //  1. don't change the function signature
    //  2. if a dunction signature is changed, you are creating a new function
    //  3. override keyword: during compilation time, check the signature
    //           if does not match, produces error.
    //  4. Once a functionis declared as virtual in the heritance hiearchy
    //       it remain virtual.
    virtual void withdraw(double) override; // add the limit --> extend the inherrited feature
                                            //--> only then, redefine it with the same function signature
};
