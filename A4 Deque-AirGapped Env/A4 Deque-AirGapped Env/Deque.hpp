#pragma once
#include <initializer_list>
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
	};
	node *head;
	node *tail;
	int count;

public:
	class iterator
	{
	private:
		node *pos;
		const Deque *container;

	public:
		iterator();
		int get() const;
		int operator*() const;
		void next();
		void operator++();
		void prev();
		void operator--();
		bool equals(Deque::iterator) const;
		bool operator==(Deque::iterator) const;
		bool operator!=(Deque::iterator) const;
		Deque::iterator operator+(int const);
		friend class Deque;
	};
	Deque();
	Deque(std::initializer_list<int>);
	Deque(const Deque &);

	~Deque();
	int size() const;
	int front() const;
	int back() const;
	void push_front(int);
	void push_back(int);
	void pop_front();
	void pop_back();
	iterator begin() const;
	iterator end() const;
	void insert(iterator, int);
	void erase(iterator);

	int at(int);
	int operator[](int);
};