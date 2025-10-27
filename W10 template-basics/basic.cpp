/*
    template function: max(10,20) for int
                       max(10.11,20.12) for double
                       max(string("hello"), string("hEllo"));
                       dictionary ordering, lexlicographical
                       --> compare ASCII values from index 0 to size() - 1
                       --> untill two ASCII values are different
*/
#include <iostream>

 //using namespace std;

template <typename T> // T: simple a symbol --> you can use anything as a symbol
                      // template prefix
T mymax(T first, T second);

// template <typename T> T max(T, T); prototype

int main()
{
    std::cout << mymax(10, 20) << std::endl;       // the template function instantiated with int --> number of bytes to be reserved for the arugments
    std::cout << mymax(10.11, 20.22) << std::endl; // the template function instantiated with double --> number of bytes to be reserved for the arugments
    std::cout << max(std::string("hello"), std::string("hEllo")) << std::endl;

    return 0;
}

template <typename T>
T mymax(T first, T second)
{
    return (first > second ? first : second); // T can be any type, even object
                                              // the class of the object must define operator>()
}
