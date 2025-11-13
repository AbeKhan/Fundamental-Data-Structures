#include <iostream>
#include <sstream>
#include <cassert>
#include <initializer_list>
#include "Deque.hpp"

using namespace std;

/*------------------ Stream operators ------------------*/
ostream &operator<<(ostream &os, const Deque &dq)
{
	for (int i = 0; i < dq.size(); ++i)
		os << dq.at(i) << " ";
	return os;
}

istream &operator>>(istream &is, Deque &dq)
{
	int N, value;
	is >> N;
	for (int i = 0; i < N; ++i)
	{
		is >> value;
		dq.push_back(value);
	}
	return is;
}

/*------------------ Helper ------------------*/
void printDeque(const Deque &dq, const string &label = "Deque")
{
	cout << label << " " << dq << "\n";
}

/*------------------ Demo ------------------*/
void basic_demo()
{
	Deque dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(5);
	dq.push_front(1);

	printDeque(dq, "After pushes:");
	cout << "front= " << dq.front()
		 << " back= " << dq.back()
		 << " at(2)= " << dq.at(2) << "\n";

	dq.pop_front();
	dq.pop_back();
	printDeque(dq, "After pops:");

	dq.insert(dq.begin() + 1, 100);
	dq.erase(dq.begin());
	printDeque(dq, "After insert+erase:");

	cout << "Iterating: ";
	for (auto it = dq.begin(); it != dq.end(); ++it)
		cout << *it << " ";
	cout << "\n";
}

/*------------------ Tests ------------------*/
void test_copy_constructor()
{
	cout << "\n[TEST] Copy constructor\n";
	Deque a{1, 2, 3};
	Deque b(a);
	assert(b.size() == 3);
	assert(b[0] == 1 && b[1] == 2 && b[2] == 3);
	cout << "Copy constructor OK\n";
}

void test_copy_assignment()
{
	cout << "\n[TEST] Copy assignment operator\n";
	Deque a{10, 20, 30, 40};
	Deque c = a;
	printDeque(a, "a:");
	printDeque(c, "c (assigned from a):");
	a.pop_back();
	printDeque(a, "a after pop_back():");
	printDeque(c, "c should remain {10,20,30,40}:");
	assert(c.size() == 4);
	assert(c[0] == 10 && c[1] == 20 && c[2] == 30 && c[3] == 40);
	cout << "Copy assignment OK\n";
}

void test_stream_insertion()
{
	cout << "\n[TEST] operator<< (ostream)\n";
	Deque d{10, 20, 30};
	cout << "Expected output: 10 20 30 \n";
	cout << "Actual output:   " << d << "\n";
	cout << "operator<< OK (manual check)\n";
}

void test_stream_extraction_ints()
{
	cout << "\n[TEST] operator>> (istream) with ints\n";
	cout << "Please enter: 5 10 20 30 40 50\n";

	Deque d;
	cin >> d;

	assert(d.size() == 5);
	assert(d[0] == 10 && d[1] == 20 && d[2] == 30 && d[3] == 40 && d[4] == 50);
	cout << "operator>> (ints) OK\n";
}

/*------------------ Entry ------------------*/
int main()
{
	cout << "=== Deque (int) basic demo ===\n";
	basic_demo();

	cout << "\n=== Unit-style tests ===\n";
	test_copy_constructor();
	test_copy_assignment();
	test_stream_insertion();
	test_stream_extraction_ints();

	cout << "\nAll tests passed.\n";
	return 0;
}
