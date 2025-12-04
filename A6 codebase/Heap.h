
/* This file Implements of a Min Heap for 'int' type elements
   by using vector
*/
#ifndef HEAP_H
#define	HEAP_H

#include <vector>
using namespace std;

class Heap {
private:
    vector<int> elements;  //instantiation of a template class vector<T>
                              //elements.size() is 0
                              //use push_back or pop_back to insert into and delete from the elements
                              //vector is a stack (LIFO) 
    
public:
    Heap();
    ~Heap();
    void  insert(int e); // adds a new element to this heap
    int   top() const;	     // gets the min element in the heap without removal
    int   removeMin();      // removes the min element from the heap
    int   size() const;     // returns the # of elements in the heap
    
private: // utility functions called by insert and removeMin

    void   heapifyDown();
    void   heapifyUp();
};

#endif	