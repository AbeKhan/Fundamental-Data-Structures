#include <iostream>
#include "pair.hpp"

using namespace std;
using namespace MyNameSpace;

int main()
{
    Pair<int> p1(10, 20); // complier instantiate myPair class with int
    cout << "first= " << endl << p1.getFirst(); //instantiate a memeber function only when it is called
    p1.print(cout);

    // Pair<int> p2(); //add the defualt constructor

    Pair<string> p2(string("hello"), string("abraham"));
    p2.print(cout);
}
