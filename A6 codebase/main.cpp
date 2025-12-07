#include <iostream>
#include "Heap.h"

using namespace std;


int main() {
    
    Heap h;
	const int SIZE = 15;
	int a[] = {41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61};

	for(int i = 0; i < SIZE; i++)
	{
		h.insert(a[i]);
	}

	cout << h << endl;
	



    return 0;
}

