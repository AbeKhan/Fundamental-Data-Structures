#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BinaryNode.h"

template <typename T>
class BinaryTree
{
//private:
protected:  //child class can directly access protected members of its parent
BinaryNode<T>* root;
    

public:
    BinaryTree();
    ~BinaryTree();
    BinaryTree(const BinaryTree<T>&);
    BinaryTree<T>& operator=(const BinaryTree<T>&);
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    //delete every node in the tree
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& right)
{

}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& right)
{

}
#endif