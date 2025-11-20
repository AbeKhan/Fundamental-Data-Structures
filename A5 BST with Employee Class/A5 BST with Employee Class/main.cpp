#include <iostream>
#include <string>

#include "BinaryTree.h"
//Please change enum.h to ErrorCode.h for a better naming
#include "ErrorCode.h"

template <typename T>
void increment(T data)  //template free function
{
    data = data + 1; 
}
void menu();
int main()
{
    BinaryTree<int> bst;
    bool exit_now = false;
    while(!exit_now) {
        menu();
        string input;
        cin >> input;
        if(input == "i") //insert mode to get multiple values to insert until the user enters q
        {

            string value; //empty string
            while(value != "q") 
            {
                cout << "Enter a value : ";
                cin >> value;
                if(value != "q")
                {
                    bst.insert(stoi(value)); //stoi(value) --> constant value, no reference
                    bst.print();
                }
            }
        }
        else if(input == "m")
        {
            bst.preorder(increment); //increase the value of every node
            bst.print();
        }

	   //complete this code to handle all the remaining menu items
    }
}

void menu()
{
    cout << "======== Menu ========" << endl;
    cout << "i. Incremental Insert" << endl; // until the user enters "q<Enter" to quit the insert mode
    cout << "r. Incremental Remove" << endl; // until the user enters "q<Enter" to quit the remove mode
    cout << "c. Clear tree" << endl;
    cout << "t. Print tree" << endl;
    cout << "h. Print tree height" << endl;
    cout << "s. Print tree size" << endl;
    cout << "m. Pre-order traversal" << endl;
    cout << "n. In-order traversal" << endl;
    cout << "p. Post-order traversal" << endl;
    cout << "l. Leaf count" << endl;
    cout << "d. operator=()" << endl;
    cout << "x. Exit" << endl;
    cout << "======== Menu ========" << endl;
}