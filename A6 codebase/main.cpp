#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
	Heap h;
	const int SIZE = 15;
	int a[] = {41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61};

	cout << "Heap() :" << &h << endl;
	cout << "==================== Insertion Test ====================" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		h.insert(a[i]);
	}
	cout << h << endl;

	cout << "==================== Sorting  Test ====================" << endl;

	for (int i = 0; i <= SIZE; i++)
	{
		try
		{
			cout << "min value : 	" << h.removeMin() << endl;
			cout << "After removeMin(): " << h << endl;
		}
		catch (const runtime_error &e)
		{
			cout << endl
				 << "Exception: " << e.what() << endl;
		}
	}

	// return 0;
}