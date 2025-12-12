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
	heapifyUp();
	// heapifyDown();
}

int Heap::top() const
{
	// TODO: return min element (elements[0])
	// For now, return 0 or throw if empty

	if (size() == 0)
	{
		throw runtime_error("Heap is empty");
	}
	return elements[1]; // root element
}

int Heap::removeMin()
{
	// 1. Replace root with the last element in the array
	// 2. Remove the last element
	// Note: 1 and 2 to keep a complete binary tree
	// 3. "Bubble down" or "percolate down" from the root by swapping with the larger (max heap) or smaller (min heap) child
	// 4. Continue until heap property is restored

	int temp = top();
	elements[1] = elements[elements.size() - 1];
	elements.pop_back();
	heapifyDown();
	heapifyUp();
	return temp;
}

int Heap::size() const
{
	return elements.size() - 1; // stub is already correct
}

ostream &operator<<(ostream &os, Heap &right)
{
	for (int i = 1; i <= right.size(); i++)
	{
		os << " " << right.elements[i] << " ";
	}
	return os;
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
	int currIdx = 1; // start at root (index 1, since index 0 is dummy)

	while (true)
	{
		int leftIdx = currIdx * 2;
		int rightIdx = currIdx * 2 + 1;
		int smallest = currIdx;

		// check left child
		if (leftIdx < elements.size() && elements[leftIdx] < elements[smallest])
		{
			smallest = leftIdx;
		}

		// check right child
		if (rightIdx < elements.size() && elements[rightIdx] < elements[smallest])
		{
			smallest = rightIdx;
		}

		// if no swap needed, heap property is satisfied
		if (smallest == currIdx)
			break;

		// swap with smaller child
		swap(elements[currIdx], elements[smallest]);

		// move down
		currIdx = smallest;
	}
}
