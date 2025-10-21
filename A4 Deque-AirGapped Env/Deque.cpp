#include "Deque.h"


//Deque functions start
Deque::Deque(int len) : length(len), pfront(nullptr), pback(nullptr){}


//Node functions start
Deque::node::node(int d) : data(d), next(nullptr), prev(nullptr) {}