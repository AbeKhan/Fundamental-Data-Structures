#include <iostream>
#include "QUEUE_H"

Queue::Queue(int c)
{
    capacity = c;
    size = 0;
    front = 0;
    rear = capacity - 1;
    data = new int[capacity]; // if not intialize  data correctly, it points to an invalid process
}

Queue::~Queue()
{
    delete[] data;
}

// Queue q1; q1.push(10); q1.push(20);
// Queue q2; q2.push(100);
// Queue q3(q2); --> copy constructor
//           --> initialize a new object by copying the value of the member varaibles of rhs
// Queue q4 = q3; --> copy constructor
Queue::Queue(const Queue &rhs)
{
    capacity = rhs.capacity;
    size = rhs.size;
    front = rhs.front;
    rear = capacity - 1;
    data = new int[capacity];
    // copy the entire array --> how to improve
    for (int i = 0; i < capacity; i++)
    {
        data[i] = rhs.data[i];
    }
}

// Queue q5;
//  q5 = q4 = q1; //chanined assigment, cascaded assignment
//  =====> q4 = q1; ==> must return q4
//                  ==> q4.operator=(q1);
//  =====> q5 = q4;
//
//  cin >> q1 >> q2; istream& operator>>(istream&, Queue q);
//  cin >> q1 must return cin, which is combined with q2 using >>

//Copy-and -Swap technique Vs. Delete-and-Copy technique
Queue &Queue::operator=(const Queue &rhs)
{
    //1. create a local copy od rhs using temp

    Queue temp(rhs);
    //2. swap data between temp and *this;
    // ==> capacity, size, front, rear, data
    int c = temp.capacity;
    temp.capacity = capacity;
    capacity = c;

    //size swap

    //front, rear swap

    //data swap
    int* p = temp.data;

    temp.data = data; //this->data
    this->> data = p;

    //3. return *this;
    return *this;

    //Delete-copy approach
    /*
    delete[] data;
    capacity = rhs.capacity;
    size = rhs.size;
    front = rhs.front;
    rear = rhs.rear;
    data = new int[capacity];   --> if the new fails, data becomes a dangling pointer
    copy data
    */
}

void push();
void pop();
bool isEmpty();
bool isFull();
