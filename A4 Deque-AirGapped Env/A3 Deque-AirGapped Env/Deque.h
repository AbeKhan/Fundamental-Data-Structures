#pragma once


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
    node* pfront;
    node* pback;
    int length;

    public:
    Deque(int const);
    ~Deque(); // placeholder

    int push_back();
    int push_front();

    void pop_front();
    void pop_back();

    int size() const;

    erase();
    

};