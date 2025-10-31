#include <cassert>
#include "list.h"

using namespace std;

list::list() : head(nullptr), tail(nullptr), count(0) {}

list::~list()
{
	while (count > 0)
	{
		pop_front();
	}
}

list::node::node(int d) : data(d), next(nullptr), prev(nullptr) {}

list::iterator::iterator() : pos(nullptr), container(nullptr) {}

//**** start == list::iteratpr member function
int list::iterator::get() const
{
	assert(pos != nullptr);
	return pos->data;
}

int list::iterator::operator*() const
{
	return list::iterator::get();
}

void list::iterator::next()
{
	if (pos == nullptr)
	{
		pos = container->head;
	}
	else
	{
		pos = pos->next;
	}
}

void list::iterator::operator++()
{
	return list::iterator::next();
}

void list::iterator::prev()
{
	if (pos == nullptr)
	{
		pos = container->tail;
	}
	else
	{
		pos = pos->prev;
	}
}

void list::iterator::operator--()
{
	return list::iterator::prev();
}

bool list::iterator::equals(list::iterator iter) const
{
	return container == iter.container && pos == iter.pos;
}

bool list::iterator::operator==(list::iterator iter) const
{
	return list::iterator::equals(iter);
}

bool list::iterator::operator!=(list::iterator iter) const
{
	return !list::iterator::equals(iter);
}
//**** end === list::iteratpr member function

int list::size() const
{
	return count;
}

int list::front() const
{
	assert(count > 0);
	return head->data;
}

int list::back() const
{
	assert(count > 0);
	return tail->data;
}

void list::push_front(int data)
{
	node *p = new node(data);
	if (count == 0)
	{
		head = tail = p;
	}
	else
	{
		p->next = head;
		head->prev = p;
		head = p;
	}
	++count;
}

void list::push_back(int data)
{
	node *p = new node(data);
	if (count == 0)
	{
		head = tail = p;
	}
	else
	{
		tail->next = p;
		p->prev = tail;
		tail = p;
	}
	++count;
}

void list::pop_front()
{
	assert(count > 0);
	if (count == 1)
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		node *discard = head;
		head = head->next;
		head->prev = nullptr;
		delete discard;
	}
	--count;
}

void list::pop_back()
{
	assert(count > 0);
	if (count == 1)
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		node *discard = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete discard;
	}
	--count;
}

list::iterator list::begin() const
{
	iterator it;
	it.pos = head;
	it.container = this;
	return it;
}

list::iterator list::end() const
{
	iterator it;
	it.pos = nullptr;
	it.container = this;
	return it;
}

void list::insert(iterator &it, int data)
{
	if (it.pos == nullptr)
	{
		// empty or append at the tail
		push_back(data);
		it.pos = tail;
	}
	else if (it.pos == head)
	{
		push_front(data);
		it.pos = head;
	}
	else
	{
		node *p = new node(data);
		node *left = it.pos->prev;
		node *right = it.pos;

		left->next = p;
		p->prev = left;
		p->next = right;
		right->prev = p;
		it.pos = p;
		++count;
	}
}

void list::erase(iterator &it)
{
	assert(it.pos != nullptr);
	if (count == 1)
	{
		delete head;
		head = tail = nullptr;
		it.pos = nullptr;
	}
	else if (it.pos == head)
	{
		node *discard = head;
		head = head->next;
		head->prev = nullptr;
		delete discard;
		it.pos = head;
	}
	else if (it.pos == tail)
	{
		node *discard = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete discard;
		it.pos = nullptr; // past the end
	}
	else
	{
		node *discard = it.pos;
		node *left = it.pos->prev;
		node *right = it.pos->next;
		left->next = right;
		right->prev = left;
		delete discard;
		it.pos = right;
	}
	--count;
}