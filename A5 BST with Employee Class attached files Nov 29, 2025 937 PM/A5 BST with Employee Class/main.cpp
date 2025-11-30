#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "BinaryTree.h"
#include "Employee.h"

using namespace std;

void menu();

void printEmployee(Employee &e)
{
	cout << e << endl; 
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cerr << "Usage: " << argv[0] << " <filename>" << endl;
		return 1;
	}

	string filename = argv[1];
	ifstream file(filename);
	if (!file)
	{
		cerr << "Error opening file: " << filename << endl;
		return 1;
	}

	BinaryTree<string, Employee> bst;

	string line;
	while (getline(file, line))
	{
		if (line.empty())
			continue;

		// Split line into tokens
		stringstream ss(line);
		vector<string> fields;
		string field;
		while (ss >> field)
		{
			fields.push_back(field);
		}

		// Construct Employee from vector<string>
		Employee temp(fields);

		// Insert into BST using SSN as key
		bst.insert(temp.getSSN(), temp);
	}

	file.close();

	// Show results
	cout << "Loaded " << bst.size() << " employees from file." << endl;
	//cout << "Inorder traversal:" << endl;
	bst.print();

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
				cout << "Enter an first name: ";
				cin >> first;

				cout << "Enter an last name: ";
				cin >> last;
				temp.setName(first, last);

				cout << "Enter an department: ";
				cin >> value;
				temp.setDept(value);

				cout << "Enter an role: ";
				cin >> value;
				temp.setRole(value);

				cout << "Enter an salary: ";
				cin >> value;
				temp.setSalary(stoi(value));

				if (value != "q")
				{
					bst.insert(temp.getSSN(), temp);
					bst.print();
				}

				cout << "Enter an q to quit, if not, enter any key to contuine. " << endl;
				cin >> value;
			}
		}
		else if (input == "r")
		{
			string key;
			string value;

			while (value != "q")
			{
				cout << "Enter the SSN you would like to delete. ";
				cin >> key;
				bst.erase(key);
				bst.print();

				cout << "Enter an q to quit, if not, enter any key to contuine. " << endl;
				cin >> value;
			}
		}
		else if (input == "c")
		{
			string value;
			cout << "Are you sure? This will remove all data. Press y to contuine, press q to quit." << endl;
			cin >> value;

			if (value == "y")
			{
				bst.clear();
				cout << "All data has been removed" << endl;
			}
			else
			{
			}
		}
		else if (input == "t")
		{
			bst.print();
			cout << "Tree has been printed" << endl;
		}
		else if (input == "h")
		{
			int height = bst.height();
			cout << "The height of the tree is " << height << " " << endl;
		}
		else if (input == "s")
		{
			int size = bst.size();
			cout << "The size of the tree is " << size << endl;
		}
		else if (input == "m")
		{
			bst.preorder(printEmployee);
			bst.print();
		}
		else if (input == "n")
		{
			bst.inorder(printEmployee);
			bst.print();
		}
		else if (input == "p")
		{
			bst.postorder(printEmployee);
			bst.print();
		}
		else if (input == "l")
		{
			int count = bst.leaf_count();
			cout << "Number of leaves: " << count << endl;
		}
		else if (input == "d")
		{
		}
		else if (input == "x")
		{
			exit_now = true;
		}
		else
		{
			cout << endl
				 << "Invaild input, try again." << endl;
		}
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