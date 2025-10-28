#pragma once
#include <string>

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

    std::string operator*() const;
    Iterator operator+(int offset) const;
    bool operator!=(const Iterator &rhs) const;

    // void operator++(int dummy);
    // void operator--(int dummy);
    // void operator==(Iterator other) const;

    friend class Node;
    friend class Deque;
};