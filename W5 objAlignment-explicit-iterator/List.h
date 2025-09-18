#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

// Forward declarations for iterators
class Iterator; // nobody, tell the complier that the dfinition of Iterator will come later
                // If Iterator is used, just let the complier pass it

// List class with singly linked list
class List
{
private:
    Node *head;

public:
    List() : head(nullptr) {}

    ~List();

    void push_back(int value);  //append

    // Methods to get iterators
    Iterator begin();   //Iterator: return type of begin()
    Iterator end();

    // Friend classes for access to private members
    friend class Iterator; //unilateral relationship
                           //But List cannot access the private memebers of Iterator
};

#endif