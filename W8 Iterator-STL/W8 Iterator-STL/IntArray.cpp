#include <iostream>

// container
class IntArray
{
    // Container just manages data
    int *data; // date is the pointer to an array in the heap
    int size;

public:
    IntArray()
    { // Resource Acqisition Is Initialization (RAII)
        size = 5;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = rand() % 100;
    }
    ~IntArray()
    {
        delete[] data;
    }

    // Iterator class for separation of concern
    class Iterator
    {
        int *ptr; // address of a data item in the container class
    public:
        Iterator(int *data) : ptr(data) {}; //

        // return type: Interator*
        // return type: Interator --> a new object --> ++it returns a new object --> losing the loop control variable
        //   for (auto it = studentGrades.begin(); it != studentGrades.end(); ++it)
        // When to use a reference: only when a varaible the reference refers to exists
        Iterator &operator++() // pre-increment must return the current object
        {
            ptr++;
            return *this; //
        }

        // it2 = it1++; x = 5, y = 6, y = x++; ==> y = 5, x = 6;
        Iterator &operator++(int) // post-increment
        {
            Iterator temp = *this;
            ptr++;
            return temp;
        }
        //*it ==> pull the value of the data item pointed by ptr of the iterator
        // Why int& instead of int? ==> data intem already occupied a memory
        //                         ==> don't want to create a new interger value
        int &operator*() // dereferencing
        {
            return *ptr;
        }

        bool operator!=(Iterator&)
        {
            return this->ptr != rhs.pts;
        }
    };

    // container's method
    Iterator begin()
    {
        return Iterator(data); // accessing the priavte member of the container class
                               //--> Iterator's ptr = data
    }

    // container's method
    Iterator end()
    {
        return Iterator(data + size);
        //--> Iterator's ptr = data + size
        //--> end(): pass the last element --> pointer to 4 bytes
        //   --> invaild pointer from the container
    }
};
