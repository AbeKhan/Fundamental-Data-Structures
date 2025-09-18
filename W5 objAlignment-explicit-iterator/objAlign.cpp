#include <iostream>

using namespace std;

struct A
{
    char c;   // 1 byte, can can be any address in the RAM
    double d; // 8 bytes, d must be located at an address of muiltple of 8
    int x;    // 4 bytes, x must be alligned with a muiltple of 4
};

struct B
{
    char c;
    int x;
    double d;
};

int main()
{
    A a;
    B b;

    cout << "sizeof(a) = " << sizeof(a) << endl;
    cout << "sizeof(b) = " << sizeof(b) << endl;

    return 0;
}