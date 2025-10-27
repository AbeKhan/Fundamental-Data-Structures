/*
 * main.cpp — Deque (non-template, int) demo + tests
 * Tests covered:
 *  - essential functions: push_back(), push_front(), front(), back(), at(position),
 *  - Copy constructor
 *  - Copy assignment operator
 *  - operator<< (ostream) for Deque
 *  - operator>> (istream) for Deque
 *  - iterator
 * operator>> input format: first an integer N, then N space-separated ints.
 *   Example input: 5 10 20 30 40 50
 */

#include <iostream>
#include <sstream>
#include <cassert>
#include <initializer_list>
#include "Deque.hpp"  // <-- Your non-template Deque<int> implementation

using namespace std;

/*------------------ Stream operators for Deque (int) ------------------*/
ostream &operator<<(ostream &os, const Deque &dq)
{
    

}

istream &operator>>(istream &is, Deque &dq)
{
    
}

/*------------------ Helper ------------------*/
void printDeque(const Deque &dq, const string &label = "Deque")
{
    cout << label << " " << dq << "\n";
}

/*------------------ Walk-through demo (live coding) ------------------*/
void basic_demo()
{
    Deque dq; // empty

    // Inserts at both ends
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    
    dq.push_front(1);

    printDeque(dq, "After pushes:");
    cout << "front=" << dq.front()
         << " back=" << dq.back()
         << " at(2)=" << dq.at(2) << "\n";

    // Deletes at both ends
    dq.pop_front();
    dq.pop_back();
    printDeque(dq, "After pops:");

    // Insert  in the middle using an iterator
    // Inset 100 into the deque before the element at position dq.begin() + 1
    // Effect: The new element becomes the second element in the deque

    dq.insert(dq.begin() + 1, 100);

    // erase in the middle using an iterator
    // removes the element at the position indicated by dq.begin(), i.e., the first element.
    // effect: all subsequent elements are shifted forward to fill the gap.
    dq.erase(dq.begin());
    printDeque(dq, "After insert+erase:");

    // Manual iteration (iterator support assumed)
    cout << "Iterating: ";
    for (auto it = dq.begin(); it != dq.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

/*------------------ Tests ------------------*/
void test_copy_constructor()
{
    cout << "\n[TEST] Copy constructor\n";
    Deque a{1, 2, 3}; // assumes initializer_list ctor

    // fill in the blank

    assert(b.size() == 3);
    assert(b[0] == 1 && b[1] == 2 && b[2] == 3);
    cout << "Copy constructor OK\n";
}

void test_copy_assignment()
{
    cout << "\n[TEST] Copy assignment operator\n";
    Deque a{10, 20, 30, 40};

    // fill this section with the necessary code

    printDeque(a, "a:");
    printDeque(c, "c (assigned from a):");

    a.pop_back(); // a becomes {10,20,30}
    printDeque(a, "a after pop_back():");
    printDeque(c, "c should remain {10,20,30,40}:");

    // fill this sectin with the necessary statements using assert()
    cout << "Copy assignment OK\n";
}

void test_stream_insertion()
{
    cout << "\n[TEST] operator<< (ostream)\n";
}

void test_stream_extraction_ints()
{
    cout << "\n[TEST] operator>> (istream) with ints\n";
    Deque d;
    // fill this sectin with the necessary code
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