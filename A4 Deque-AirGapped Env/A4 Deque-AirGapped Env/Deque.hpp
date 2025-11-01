#pragma once
#include <cassert>
#include <initializer_list>

class Deque {
private:
    struct node {
        int data;
        node* next;
        node* prev;
        node(int d);
    };

    node* head;
    node* tail;
    int count;

public:
    class iterator {
    public:
        iterator();
        int get() const;
        int operator*() const;
        void next();
        iterator& operator++();
        iterator operator+(int val);
        void prev();
        iterator& operator--();
        bool equals(iterator iter) const;
        bool operator==(iterator iter) const;
        bool operator!=(iterator iter) const;

        node* pos;
        const Deque* container;
    };

    Deque();
    Deque(std::initializer_list<int> data);
    Deque(const Deque& old);
    ~Deque();

    int size() const;
    int front() const;
    int back() const;
    int at(int nPos) const;
    int operator[](int nPos) const;

    void push_front(int data);
    void push_back(int data);
    void pop_front();
    void pop_back();

    void insert(iterator it, int data);
    void erase(iterator it);

    iterator begin() const;
    iterator end() const;
};
