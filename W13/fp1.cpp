#include <iostream>

using namespace std;

void win()
{
	cout << "You win" << endl;
}

void lose()
{
	cout << "You lose" << endl;
}

int main()
{
	srand(time(0));

	
	//int* x; --> x points to an adress where int is stored
	// void: return type of a function
	//  *pf: a pointer variable name fp
	// (): for parameter argument/variables
	// function pointer: the adress of the code of a function
	void (*fp)(); //fp points to an address of a function that does not return anything

	//in C/C++, the name of a function: is its address
	//fp = lose;
	//fp = %lose;
	fp = rand() % 2 ? win : lose; // non zero: true

	//call the function using fp
	fp();

	return 0;
}