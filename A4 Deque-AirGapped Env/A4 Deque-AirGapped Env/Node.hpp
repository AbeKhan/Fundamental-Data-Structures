#pragma once

class Node
{
    int data;
    Node *next;
    Node *prev;

    friend class Deque;
    friend class Iterator;

public:
    Node(int);
    ~Node(); // placeholder
};