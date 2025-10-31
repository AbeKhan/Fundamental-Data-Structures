#pragma once

class list
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
		const list *container;

	public:
		iterator();
		int get() const;
		int operator*() const;
		void next();
		void operator++();
		void prev();
		void operator--();
		bool equals(list::iterator) const;
		bool operator==(list::iterator) const;
		bool operator!=(list::iterator) const;
		friend class list;
	};
	list();
	~list();
	int size() const;
	int front() const;
	int back() const;
	void push_front(int);
	void push_back(int);
	void pop_front();
	void pop_back();
	iterator begin() const;
	iterator end() const;
	void insert(iterator &, int);
	void erase(iterator &);
};