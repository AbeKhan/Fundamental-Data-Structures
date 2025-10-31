#include <cassert>
#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
#include "list.h"

void white_box_data(int);

void insert_v(vector<int> &v, int pos, int data);
void insert_list(list &m, int pos, int data);
void erase_v(vector<int> &v, int pos);
void erase_list(list &m, int pos);

int main()
{
	list m;
	assert(m.size() == 0);

	m.push_front(10);
	assert(m.size() == 1);
	assert(m.front() == 10);
	assert(m.back() == 10);
	m.push_front(20); // 20 10
	assert(m.size() == 2);
	assert(m.front() == 20);
	assert(m.back() == 10);

	m.push_back(30); // 20 10 30
	assert(m.size() == 3);
	assert(m.front() == 20);
	assert(m.back() == 30);
	m.push_back(40); // 20 10 30 40
	assert(m.size() == 4);
	assert(m.front() == 20);
	assert(m.back() == 40);

	m.pop_front(); // 10 30 40
	assert(m.size() == 3);
	assert(m.front() == 10);
	assert(m.back() == 40);

	m.pop_front(); //  30 40
	assert(m.size() == 2);
	assert(m.front() == 30);
	assert(m.back() == 40);

	m.pop_back(); // 30
	assert(m.size() == 1);
	assert(m.front() == 30);
	assert(m.back() == 30);
	m.pop_back(); // empty
	assert(m.size() == 0);

	list a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30); // 10 20 30
	list::iterator it = a.begin();
	assert(it.get() == 10);
	it.next();
	assert(it.get() == 20);
	it.next();
	assert(it.get() == 30);
	it.next(); // nullptr
	it.next(); // begin from the head
	assert(it.get() == 10);
	list::iterator it2 = a.end();
	it2.prev();
	assert(it2.get() == 30);
	it2.prev();
	assert(it2.get() == 20);
	it2.prev();
	assert(it2.get() == 10);
	it2.prev();
	it2.next();
	assert(it2.get() == 10);

	list test;
	list::iterator it3 = test.begin();
	test.insert(it3, 11);
	assert(test.size() == 1);
	assert(test.front() == 11);
	assert(test.back() == 11);
	it3.next();
	test.insert(it3, 12); // 11 12
	assert(test.size() == 2);
	assert(test.front() == 11);
	assert(test.back() == 12);

	it3 = test.begin();
	test.insert(it3, 33); // 33 11 12
	assert(test.size() == 3);
	assert(test.front() == 33);
	assert(test.back() == 12);

	it3.next();			  // it.pos ==> 11
	test.insert(it3, 44); // 33 44 11 12
	assert(test.size() == 4);
	assert(test.front() == 33);
	assert(test.back() == 12);
	it3 = test.begin();
	assert(test.front() == 33);
	assert(it3.get() == 33);
	it3.next();
	assert(it3.get() == 44);
	it3.next();
	assert(it3.get() == 11);
	it3.next();
	assert(it3.get() == 12);

	it3 = test.begin();
	test.erase(it3);
	assert(test.size() == 3);
	assert(test.front() == 44);
	assert(test.back() == 12);
	assert(it3.get() == 44);
	it3 = test.end();
	it3.prev(); // tail
	test.erase(it3);
	assert(test.size() == 2);
	assert(test.front() == 44);
	assert(test.back() == 11);
	it3.prev();
	assert(it3.get() == 11);

	test.push_back(33);
	test.push_back(55);
	it3 = test.begin();
	it3.next();
	it3.next();
	test.erase(it3);
	assert(it3.get() == 55);
	assert(test.size() == 3);
	assert(test.front() == 44);
	assert(test.back() == 55);

	test.pop_front();
	test.pop_front();
	it3 = test.begin();
	test.erase(it3);
	assert(test.size() == 0);
	test.push_back(99);
	it3 = test.begin();
	test.insert(it3, 100);
	assert(test.front() == 100);
	assert(test.back() == 99);

	test.push_back(20);
	test.push_back(30);
	test.push_back(40);

	list::iterator n = test.begin();
	list::iterator n2 = test.begin();
	n2.next();
	cout << "n2: " << n2.get() << endl;
	while (n != test.end())
	{
		// cout << n.get() << " ";
		cout << *n << " ";
		// n.next();
		++n;
	}
	cout << endl;
	n2.next();
	cout << "n2: " << n2.get() << endl;

	for (list::iterator it = test.begin(); it != test.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "white_box_test " << i << endl;
		white_box_data(20000);
	}
}

void white_box_data(int size)
{
	random_device r;
	uniform_int_distribution<int> dist_max(0, numeric_limits<int>::max());
	uniform_int_distribution<int> dist_10(1, 10);

	int test_data[size];
	for (int i = 0; i < size; i++)
	{
		test_data[i] = i;
	}
	shuffle(test_data, test_data + size, default_random_engine(r()));

	list test;
	vector<int> v;

	test.push_back(test_data[0]);
	v.push_back(test_data[0]);
	for (int i = 1; i < size; i++)
	{
		int chance = dist_10(r);
		if (chance == 1)
		{
			insert_list(test, 0, test_data[i]);
			insert_v(v, 0, test_data[i]);
		}
		else if (chance == 2)
		{
			insert_list(test, test.size(), test_data[i]);
			v.push_back(test_data[i]);
		}

		else
		{
			int pos = dist_max(r) % (test.size() + 1);
			insert_list(test, pos, test_data[i]);
			insert_v(v, pos, test_data[i]);
		}
	}

	assert(test.size() == v.size());
	int i = 0;
	for (list::iterator it = test.begin(); it != test.end(); ++it, ++i)
	{
		assert(*it == v[i]);
	}

	for (int i = 0; i < size / 2; i++)
	{
		int chance = dist_10(r);
		if (chance == 0 && test.size() > 0)
		{
			erase_list(test, 0);
			erase_v(v, 0);
		}
		else if (chance == 2 && test.size() > 0)
		{
			erase_list(test, test.size() - 1);
			erase_v(v, test.size() - 1);
		}
		else if (test.size() > 0)
		{
			int pos = dist_max(r) % test.size();
			erase_list(test, pos);
			erase_v(v, pos);
		}
	}

	assert(test.size() == v.size());
	int i = 0;
	for (list::iterator it = test.begin(); it != test.end(); ++it, ++i)
	{
		assert(*it == v[i]);
	}
}

void insert_v(vector<int> &v, int pos, int data)
{
	vector<int>::iterator it = v.begin();
	for (int i = 0; i < pos; i++)
	{
		++it;
	}
	v.insert(it, data);
}

void insert_list(list &m, int pos, int data)
{
	list::iterator it = m.begin();
	for (int i = 0; i < pos; i++)
	{
		++it;
	}
	m.insert(it, data);
}

void erase_v(vector<int> &v, int pos)
{
	vector<int>::iterator it = v.begin();
	for (int i = 0; i < pos; i++)
	{
		++it;
	}
	v.erase(it);
}

void erase_list(list &m, int pos)
{
	list::iterator it = m.begin();
	for (int i = 0; i < pos; i++)
	{
		++it;
	}
	m.erase(it);
}
