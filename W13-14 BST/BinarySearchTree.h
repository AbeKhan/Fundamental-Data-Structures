#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryNode.h"
#include "BinaryTree.h"
#include "ErrorCode.h"

using namespace std;

template <class T>
class BinarySearchTree: public BinaryTree<T> {
public:
   Error_code insert(const T& new_data);
   Error_code remove(const T& old_data);
   //Error_code tree_search(T& target) const;
protected:

   // Auxiliary functions called by the public functions
   Error_code recursive_insert(BinaryNode<T>*& sub_root, const T& new_data);
   Error_code recursive_delete(BinaryNode<T>*& sub_root, const T& target);
 
};


template <class T>
Error_code BinarySearchTree<T>::insert(const T &new_data)
{
   return recursive_insert(this->root, new_data);	//root in BT, not BST
}


template <class T>
Error_code BinarySearchTree<T>::recursive_insert(BinaryNode<T>*& sub_root, const T &new_data)
{
	Error_code result = success;

	if(sub_root == nullptr) //time to insert
	{
		BinaryNode<T>* newNode = new BinaryNode<T>(new_data);
		sub_root = newNode;
	}
	else if(sub_root->data == new_data)
	{
		result = duplicate_error;
	}
	else if(sub_root->data < new_data) //do down to RST
	{
		result = recursive_insert(sub_root->right, new_data);
	}
	else if(sub_root->data > new_data)
	{
		result = recursive_insert(sub_root->left, new_data);
	}

	return result;
}


template <class T>
Error_code BinarySearchTree<T>::remove(const T &target)
/*
Post: If a T with a key matching that of target belongs to the
      BinarySearchTree, a code of success is returned, and the corresponding node
      is removed from the tree.  Otherwise, a code of not_present is returned.
Uses: Function recursive_delete
*/
{
   return recursive_delete(this->root, target);
}


template <class T>
Error_code BinarySearchTree<T>::recursive_delete(BinaryNode<T>*& sub_root, const T& target)
/*
Pre:  sub_root is either NULL or points to a subtree of the BinarySearchTree.
Post: If the key of target is not in the subtree, a code of not_present
      is returned.  Otherwise, a code of success is returned and the subtree
      node containing target has been removed in such a way that
      the properties of a binary search tree have been preserved.
Uses: Functions recursive_delete recursively
*/
{
	if(sub_root->data == target)
	{
		if(sub_root->right == nullptr && sub_root->left == nullptr) //no childeren
		{
			delete sub_root;
			sub_root == nullptr;
		}
		else if(sub_root->right == nullptr || sub_root->left == nullptr) //one child
		{
			if(sub_root->left != nullptr)
				BinaryNode<T>* temp = sub_root;
				sub_root = sub_root->left;
				delete temp;
		}
	}
	else //2 child case
	{
			
	}

}

#endif