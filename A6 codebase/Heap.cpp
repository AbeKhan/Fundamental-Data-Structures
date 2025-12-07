#include <stdexcept> // for exceptions
#include <iostream>
#include "Heap.h"

using namespace std;

// stub, code that is not finished, but will still complie

Heap::Heap()
{
	// constructor stub
	elements.push_back(-1); // size of the vector: 1
							// actual size of heap: 0
	cout << "Heap() :" << this << endl;
}

Heap::~Heap()
{
	// destructor stub
	cout << "~Heap() :" << this << endl;
}

void Heap::insert(int value)
{
	// 1. push value into vector to make a complete binary tree
	// 2. call heapifyUp() by comparing with parent and swapping if needed
	// 3. continue until heap property is restored
	elements.push_back(value);
	cout << value << " inserted" << endl;
	heapifyUp();
}

int Heap::top() const
{
	// TODO: return min element (elements[0])
	// For now, return 0 or throw if empty
}

int Heap::removeMin()
{
	// 1. Replace root with the last element in the array
	// 2. Remove the last element
	// Note: 1 and 2 to keep a complete binary tree
	// 3. "Bubble down" or "percolate down" from the root by swapping with the larger (max heap) or smaller (min heap) child
	// 4. Continue until heap property is restored
}

int Heap::size() const
{
	return elements.size() - 1; // stub is already correct
}

ostream& operator<<(ostream& os , Heap& right)
{
	for(int i = 1; i < right.size(); i++)
	{
		os << right.elements[i] << " ";
	}
}

void Heap::heapifyUp()
{
	// TODO: percolate last element upward

	int currIdx = elements.size() - 1; // where the new value is at
	int newVal = elements[currIdx];

	bool isFixed = false;
	while (!isFixed) // continuation condition
	{
		int pIdx = currIdx / 2;
		if (pIdx != 0 && elements[pIdx] > newVal)
		{
			// swap values
			int temp = newVal;
			elements[currIdx] = elements[pIdx];
			elements[pIdx] = temp;

			// change curIdx
			currIdx = pIdx;
		}
		else // pIdx == 0 or elements[pIdx] < newValue
		{
			isFixed = true;
		}
	}
}

void Heap::heapifyDown()
{
	// TODO: percolate root element downward
}


