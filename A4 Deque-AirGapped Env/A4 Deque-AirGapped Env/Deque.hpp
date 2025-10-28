#pragma once

#include <string>
#include "Node.hpp"
#include "Iterator.hpp"

class Deque
{

private:
    Node *pfront;
    Node *pback;
    int length;
    friend class Iterator;

public:
    Deque();
    ~Deque(); // placeholder

    int push_back(int);
    int push_front(int);

    void pop_front();
    void pop_back();
    int at(int);

    int front();
    int back();

    int size() const;

    Iterator erase(Iterator);
    void insert(Iterator, int); // position and values ??
    Iterator begin();
    Iterator end();
};