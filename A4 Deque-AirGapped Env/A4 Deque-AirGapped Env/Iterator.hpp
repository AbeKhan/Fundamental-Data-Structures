#pragma once

class Iterator
{
    Node *position;
    Deque *container;
friend class Deque;
public:
    Iterator();
    int get() const;
    void next();
    void previous();
    bool equals(Iterator other) const;

    friend class Node;
    friend class Deque;
};