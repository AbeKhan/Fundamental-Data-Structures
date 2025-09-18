#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers = {10,20,30,40,50};

    vector<int>::iterator it;
    //it++ --> operator ++ is defined in the iternator class
    for(it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << (*it) << " "; //*it
                              //operator * must be defined in the iterator class
    }


   // string s = "abc" + string ("abd"); string concatenation opreator + -> defined in the string class
    cout << endl;
    return 0;
}