#pragma once

#include <string>

class Deque
{

private:
    class node
    {
    public:
        int data;
        node *next;
        node *prev;
        node(int);
        ~node(); // placeholder
    };
    node *pfront;
    node *pback;
    int length;

public:
    Deque(int const);
    ~Deque(); // placeholder

    int push_back(int);
    int push_front(int);

    void pop_front();
    void pop_back();
    int at(int);

    std::string front();
    std::string back();

    int size() const;

    void erase(int);
    void insert(int, int); //position and values

    int begin();
    int end();
};