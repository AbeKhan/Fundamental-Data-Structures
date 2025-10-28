#include "Deque.hpp"
#include "Iterator.hpp"
#include "Node.hpp"
#include <iostream>

// Deque functions start
Deque::Deque() : length(-1), pfront(nullptr), pback(nullptr) {}

// Node functions start
// Deque::Node::Node(int d) : data(d), next(nullptr), prev(nullptr) {}

int Deque::push_back(int data)
{
    if (length == 0)
    {
        Node *n = new Node(data);

        pfront = pback = n;

        delete n;
    }
    else
    {
        Node *n = new Node(data);

        n->prev = pback;
        pback->next = n;
        pback = n;

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
    else
    {
        // change for push_front
        Node *n = new Node(data);

        n->next = pfront;
        pfront->prev = n;
        pfront = n;

        delete n;
    }
}

void Deque::pop_front()
{
    if (length == 0)
    {
        std::cout << "Nothing to remove." << std::endl;
    }
    else
    {
        Node* temp = pfront;
        pfront = pfront->next;
        delete temp;
    }
}
void Deque::pop_back()
{
    if (length == 0)
    {
        std::cout << "Nothing to remove." << std::endl;
    }
    else
    {
        Node* temp = pback;
        pback = pback->prev;
        delete temp;
    }
}
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

Iterator Deque::erase(Iterator it)
{
    Node *remove = it.position;
    Node *before = remove->prev;
    Node *after = remove->next;
    if (remove == pfront)
    {
        pfront = after;
    }
    else
    {
        before->next = after;
    }
    if (remove == pback)
    {
        pback = before;
    }
    else
    {
        after->prev = before;
    }
    delete remove;
    Iterator r;
    r.position = after;
    r.container = this;
    return r;
}
void Deque::insert(Iterator it, int data) // position and values
{
    if (it.position == nullptr)
    {
        push_back(data);
        return;
    }
    Node *after = it.position;
    Node *before = after->prev;
    Node *new_node = new Node(data);
    new_node->prev = before;
    new_node->next = after;
    after->prev = new_node;
    if (before == nullptr) // Insert at beginning
    {
        pfront = new_node;
    }
    else
    {
        before->next = new_node;
    }
}

Iterator Deque::begin() // Iterator class? Review and check how to impliment.
{
    Iterator it;
    it.position = pfront;
    it.container = this;
    return it;
}
Iterator Deque::end()
{
    Iterator it;
    it.position = nullptr;
    it.container = this;
    return it;
}

Iterator Iterator::operator+(int offset) const {
    Iterator result = *this;
    for (int i = 0; i < offset && result.position != nullptr; ++i) {
        result.position = result.position->next;
    }
    return result;
}

bool Iterator::operator!=(const Iterator& rhs) const {
    return this->position != rhs.position;
}
