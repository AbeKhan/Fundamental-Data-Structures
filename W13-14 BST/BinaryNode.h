#pragma once

template <typename T>

struct Node{
	T data;
	Node<T>* left;
	Node<T>* right;


template <typename T>
Node(T val) : data(val), left(nullptr), right(nullptr) {}
};