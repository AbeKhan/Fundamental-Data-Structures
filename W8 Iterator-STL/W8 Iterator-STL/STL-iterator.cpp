// Three completely different containers
#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

int main()
{
    vector<int> myVector = {1, 2, 3, 4, 5};
    list<int> myList = {1, 2, 3, 4, 5};
    set<int> mySet = {1, 2, 3, 4, 5};

    // THE EXACT SAME CODE works for all three!
    //containerObject.begin() --> return vector<int>::Iterator
    //containerObject.end()
    //++it ==> ++IteratorObj --> Iterator provides operator++()
    //it++ ==> IteratorObj++ --> Iterator provides operator++(int)
    //                       ==> int --> dummy, can pass any value of int
    //                       ==> there is no way to tell the difference between the two with the name itself


    //auto is used in this case because the code for vector, list and set all uses the same code. 
    //This allows any of the data type to use this code.
    //Also, this makes the code easier to read

    // obj it is assigned to the return value of begin()
    // obj it is compared with the return calue of end(): object comparison
    // object it ==> ++it ==> operator++() must return the it itself
    for (auto it = myVector.begin(); it != myVector.end(); ++it)
    {
        cout << *it << " "; //operator*() for Iterator
    }

    for (auto it = myList.begin(); it != myList.end(); ++it)
    {
        cout << *it << " ";
    }

    for (auto it = mySet.begin(); it != mySet.end(); ++it)
    {
        cout << *it << " ";
    }
}