#include <cassert>
#include <initializer_list>
#include "Deque.hpp"


using namespace std;

Deque::Deque() : head(nullptr), tail(nullptr), count(0) {}

Deque::Deque(initializer_list<int> data)
{
	for (int d : data)
	{
		push_back(d);
	}
}

Deque::Deque(const Deque &old)
{
	head = old.head;
	tail = old.tail;
	count = old.count;
}

Deque::~Deque()
{
	while (count > 0)
	{
		pop_front();
	}
}

Deque::node::node(int d) : data(d), next(nullptr), prev(nullptr) {}

Deque::iterator::iterator() : pos(nullptr), container(nullptr) {}

//**** start == Deque::iteratpr member function
int Deque::iterator::get() const
{
	assert(pos != nullptr);
	return pos->data;
}

int Deque::at(int nPos)
{
	assert(count >= nPos);
	node *n;
	n = head;
	for (int i = 0; i < nPos; i++)
	{
		n = n->next;
	}

	return n->data;
}

int Deque::iterator::operator*() const
{
	return Deque::iterator::get();
}

void Deque::iterator::next()
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

void Deque::iterator::operator++()
{
	return Deque::iterator::next();
}

Deque::iterator Deque::iterator::operator+(int const val)
{
	for (int i = 0; i < val; i++)
	{
		next();
	}

	return *this;
}

void Deque::iterator::prev()
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

void Deque::iterator::operator--()
{
	return Deque::iterator::prev();
}

bool Deque::iterator::equals(Deque::iterator iter) const
{
	return container == iter.container && pos == iter.pos;
}

bool Deque::iterator::operator==(Deque::iterator iter) const
{
	return Deque::iterator::equals(iter);
}

bool Deque::iterator::operator!=(Deque::iterator iter) const
{
	return !Deque::iterator::equals(iter);
}
//**** end === Deque::iteratpr member function

int Deque::size() const
{
	return count;
}

int Deque::front() const
{
	assert(count > 0);
	return head->data;
}

int Deque::back() const
{
	assert(count > 0);
	return tail->data;
}

void Deque::push_front(int data)
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

void Deque::push_back(int data)
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

void Deque::pop_front()
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

void Deque::pop_back()
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

Deque::iterator Deque::begin() const
{
	iterator it;
	it.pos = head;
	it.container = this;
	return it;
}

Deque::iterator Deque::end() const
{
	iterator it;
	it.pos = nullptr;
	it.container = this;
	return it;
}

void Deque::insert(iterator it, int data)
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
	}
	++count;
}

void Deque::erase(iterator it)
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

int Deque::operator[](int nPos)
{
	return at(nPos);
}