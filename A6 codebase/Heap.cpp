#include <stdexcept>   // for exceptions
#include "Heap.h"

using namespace std;

Heap::Heap() {
    // constructor stub
}

Heap::~Heap() {
    // destructor stub
}

void Heap::insert(int value) {
    // 1. push value into vector to make a complete binary tree
    // 2. call heapifyUp() by comparing with parent and swapping if needed
    // 3. continue until heap property is restored
}

int Heap::top() const {
    // TODO: return min element (elements[0])
    // For now, return 0 or throw if empty

}

int Heap::removeMin() {
    //1. Replace root with the last element in the array
    //2. Remove the last element
    //Note: 1 and 2 to keep a complete binary tree
    //3. "Bubble down" or "percolate down" from the root by swapping with the larger (max heap) or smaller (min heap) child
    //4. Continue until heap property is restored

}

int Heap::size() const {
    return elements.size();  // stub is already correct
}

void Heap::heapifyUp() {
    // TODO: percolate last element upward
}

void Heap::heapifyDown() {
    // TODO: percolate root element downward
}
