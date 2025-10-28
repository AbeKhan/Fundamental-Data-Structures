#pragma once

class Node
{
    int data;
    Node *prev;
    Node *next;
    

    friend class Deque;
    friend class Iterator;

public:
    Node(int);
    ~Node(); // placeholder
};