#include <iostream>
#include <string>

using namespace std;


//enum typename {val1, val2, val3};
//INT: 0, DOUBLE=1, STRING=2
//DataType as a data type can have only discrete int values
enum DataType {INT=3, DOUBLE=5, STRING=7};
struct Node{
    void* ptr;
    DataType dt;
    Node* next;

};

int main()
{
    Node* firstNode = new Node;
    firstNode->dt = INT;
    firstNode->next = nullptr;
    firstNode->ptr = (void*) (new int); //new int --> int*
    *((int*) (firstNode->ptr)) = 30;

    Node* secondNode = new Node;
    secondNode->dt = STRING;
    secondNode->next = firstNode;
    secondNode->ptr = (void*) (new string); //new int --> int*
    *((string*) (secondNode->ptr)) = "abcdefg";


    cout << "Linked List: " << endl;
    cout <<  *((string*) (secondNode->ptr)) << " ";
    Node* p = secondNode->next;
    if(p->dt == INT)
    {
        cout << *((int*) (firstNode->ptr)) << " ";
    }
    else if(p->dt == DOUBLE)
    {
        cout << *((double*) (firstNode->ptr)) << " ";
    }
    else if(p->dt == STRING)
    {
        cout << *((string*) (firstNode->ptr)) << " ";
    }
    cout << endl;


    // DataType dt; // DataType: data type, dt: a variable name
    // dt = INT;
    // cout << "dt = " << dt << endl;

    // cout << "sizeOf(DataType) = " << sizeof(DataType) << endl;
    // cout << "sizeOf(dt) = " << sizeof(dt) << endl;
    return 0;

}