#include "Deque.hpp"
#include <iostream>

Deque::Deque() : head(nullptr), tail(nullptr), count(0) {}

Deque::Deque(std::initializer_list<int> data) : head(nullptr), tail(nullptr), count(0) {
    for (int d : data) push_back(d);
}

Deque::Deque(const Deque& old) : head(nullptr), tail(nullptr), count(0) {
    for (node* curr = old.head; curr != nullptr; curr = curr->next)
        push_back(curr->data);
}

Deque::~Deque() {
    while (count > 0) pop_front();
}

Deque::node::node(int d) : data(d), next(nullptr), prev(nullptr) {}

Deque::iterator::iterator() : pos(nullptr), container(nullptr) {}

int Deque::iterator::get() const {
    assert(pos != nullptr);
    return pos->data;
}

int Deque::iterator::operator*() const {
    return get();
}

void Deque::iterator::next() {
    pos = (pos == nullptr) ? container->head : pos->next;
}

Deque::iterator& Deque::iterator::operator++() {
    next();
    return *this;
}

Deque::iterator Deque::iterator::operator+(int val) {
    iterator temp = *this;
    for (int i = 0; i < val; ++i) ++temp;
    return temp;
}

void Deque::iterator::prev() {
    pos = (pos == nullptr) ? container->tail : pos->prev;
}

Deque::iterator& Deque::iterator::operator--() {
    prev();
    return *this;
}

bool Deque::iterator::equals(iterator iter) const {
    return container == iter.container && pos == iter.pos;
}

bool Deque::iterator::operator==(iterator iter) const {
    return equals(iter);
}

bool Deque::iterator::operator!=(iterator iter) const {
    return !equals(iter);
}

int Deque::size() const { return count; }

int Deque::front() const {
    assert(count > 0);
    return head->data;
}

int Deque::back() const {
    assert(count > 0);
    return tail->data;
}

int Deque::at(int nPos) const{
    assert(nPos >= 0 && nPos < count);
    node* n = head;
    for (int i = 0; i < nPos; ++i) n = n->next;
    return n->data;
}

int Deque::operator[](int nPos) const{
    return at(nPos);
}

void Deque::push_front(int data) {
    node* p = new node(data);
    if (count == 0) head = tail = p;
    else {
        p->next = head;
        head->prev = p;
        head = p;
    }
    ++count;
}

void Deque::push_back(int data) {
    node* p = new node(data);
    if (count == 0) head = tail = p;
    else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
    ++count;
}

void Deque::pop_front() {
    assert(count > 0);
    if (count == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        node* discard = head;
        head = head->next;
        head->prev = nullptr;
        delete discard;
    }
    --count;
}

void Deque::pop_back() {
    assert(count > 0);
    if (count == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        node* discard = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete discard;
    }
    --count;
}

Deque::iterator Deque::begin() const {
    iterator it;
    it.pos = head;
    it.container = this;
    return it;
}

Deque::iterator Deque::end() const {
    iterator it;
    it.pos = nullptr;
    it.container = this;
    return it;
}

void Deque::insert(iterator it, int data) {
    if (it.pos == nullptr) {
        push_back(data);
        it.pos = tail;
    } else if (it.pos == head) {
        push_front(data);
        it.pos = head;
    } else {
        node* p = new node(data);
        node* left = it.pos->prev;
        node* right = it.pos;
        left->next = p;
        p->prev = left;
        p->next = right;
        right->prev = p;
        it.pos = p;
    }
    ++count;
}

void Deque::erase(iterator it) {
    assert(it.pos != nullptr);
    if (count == 1) {
        delete head;
        head = tail = nullptr;
        it.pos = nullptr;
    } else if (it.pos == head) {
        node* discard = head;
        head = head->next;
        head->prev = nullptr;
        delete discard;
        it.pos = head;
    } else if (it.pos == tail) {
        node* discard = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete discard;
        it.pos = nullptr;
    } else {
        node* discard = it.pos;
        node* left = discard->prev;
        node* right = discard->next;
        left->next = right;
        right->prev = left;
        delete discard;
        it.pos = right;
    }
    --count;
}
