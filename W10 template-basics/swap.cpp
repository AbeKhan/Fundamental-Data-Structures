
#include <iostream>

using namespace std;

template <typename T> // T: simple a symbol --> you can use anything as a symbol
                      // template prefix
T myswap(T, T);

// template <typename T> T max(T, T); prototype

int main()
{

    int i = 0, ii = 2;
    std::cout << "Before value of i :" << i << endl << " value of ii :" << ii << endl;
    myswap(i, ii);
    cout << "value of i :" << i << " value of ii :" << ii << endl;
    return 0;
}

template <typename T>
T myswap(T& first, T& second) // Can only pass variables, constants cannot be passed.
{
   T temp = first;
    *first = *second;
    *second = temp;
}
