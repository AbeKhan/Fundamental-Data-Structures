#ifdef QUEUE_H
#define QUEUE_H

class Queue
{
private:
    int capacity;
    int size;
    int front, rear;
    int *data; // heap

public:
    Queue(int c);
    // The Big Three! must be defined when an object stores data in the heap
    //       ==> how to know? ==> a pointer variable as a memeber
    // Destructor
    ~Queue();
    // Copy constructor
    Queue(const Queue &rhs); // copy an existing Queue object
    // Copy assignment operator
    Queue &operator=(const Queue &rhs);

    void push();
    void pop();
    bool isEmpty();
    bool isFull();
}

#endif