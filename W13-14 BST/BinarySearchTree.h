#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BinaryNode.h"
#include "BinaryTree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
	void insert(T&);
protected:
	Error_code_recursie_insert(BinaryNode<T>*, T);
};

#endif