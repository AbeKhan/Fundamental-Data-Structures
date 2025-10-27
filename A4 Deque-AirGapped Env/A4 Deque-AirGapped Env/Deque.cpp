#include "Deque.hpp"

// Deque functions start
Deque::Deque() : length(-1), pfront(nullptr), pback(nullptr) {}

// Node functions start
Deque::Node::Node(int d) : data(d), next(nullptr), prev(nullptr) {}

int Deque::push_back(int data)
{
    if (length == 0)
    {
        Node *n = new Node(data);

        pfront = pback = n;

        delete n;
    }
    else if (length == 1)
    {

        Node *n = new Node(data);

        pback = n;
        pfront->next = pback;
        pback->prev = pfront;

        delete n;
    }
    else
    {
        Node *n = new Node(data);

        pback->prev = pback;
        pback = n;
        pfront->next = pback;

        delete n;
    }
}

int Deque::push_front(int data)
{
    if (length == 0)
    {
        Node *n = new Node(data);

        pfront = pback = n;

        delete n;
    }
    else if (length == 1)
    {

        Node *n = new Node(data);

        pback = n;
        pfront->next = pback;
        pback->prev = pfront;

        delete n;
    }
    else
    {
        // change for push_front
        Node *n = new Node(data);

        n->next = pfront;
        pfront = n;

        delete n;
    }
}

void pop_front();
void pop_back();
int at(int);

int Deque::front()
{
    return pfront->data;
}
int Deque::back()
{
    return pback->data;
}

int Deque::size() const
{
    return length;
}

void erase(int);
void insert(int, int); // position and values

Iterator Deque::begin() // Iterator class? Review and check how to impliment.
{
    Iterator it;
    it.position = pfront;
    it.container = this;
    return it;
} 
int end();