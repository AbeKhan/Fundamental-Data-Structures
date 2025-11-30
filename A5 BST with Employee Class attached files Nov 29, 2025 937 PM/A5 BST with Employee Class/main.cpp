#include <iostream>
#include <fstream>
#include <string>

#include "BinaryTree.h"
// Please change enum.h to ErrorCode.h for a better naming
#include "ErrorCode.h"
#include "Employee.h"

// template <typename T>
// void increment(T data) // template free function
// {
//     data = data + 1;
// }

void menu();
int main()
{
    BinaryTree<string, Employee> bst; // BinarySearchTree<string>, Employee> bst
    bool exit_now = false;
    while (!exit_now)
    {
        menu();
        string input;
        cin >> input;
        if (input == "i") // insert mode to get multiple values to insert until the user enters q
        {

            string value; // empty string
            while (value != "q")
            {
                Employee temp;

                temp.setEmpCode("S");

                cout << "Enter an SSN : ";
                cin >> value;
                temp.setSSN(value);

                string first, last;
                cout << "Enter an first name:";
                cin >> first;

                cout << "Enter an first name:";
                cin >> last;
                temp.setName(first, last);

                cout << "Enter an department : ";
                cin >> value;
                temp.setDept(value);

                cout << "Enter an role : ";
                cin >> value;
                temp.setRole(value);

                cout << "Enter an salary : ";
                cin >> value;
                temp.setSalary(stoi(value));

                if (value != "q")
                {
                    bst.insert(temp.getSSN(), temp);
                    bst.print();
                }
            }
        }
        else if (input == "r")
        {
        }
        else if (input == "c")
        {
        }
        else if (input == "t")
        {
        }
        else if (input == "h")
        {
        }
        else if (input == "s")
        {
        }
        else if (input == "m")
        {
           // bst.preorder(); // increase the value of every node
            bst.print();
        }
        else if (input == "n")
        {
        }
        else if (input == "p")
        {
        }
        else if (input == "l")
        {
        }
        else if (input == "d")
        {
        }
        else if (input == "x")
        {
            exit_now = true;
        }

        // complete this code to handle all the remaining menu items
    }
}

void menu()
{
    cout << "======== Menu ========" << endl;
    cout << "i. Insert" << endl; // until the user enters "q<Enter" to quit the insert mode
    cout << "r. Remove" << endl; // until the user enters "q<Enter" to quit the remove mode
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