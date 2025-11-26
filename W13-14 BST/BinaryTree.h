#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <iomanip>
#include "BinaryNode.h"

using namespace std;

template <typename T>
class BinaryTree
{
public:
	BinaryTree();
	bool empty() const;
	void preorder(void (*visit)(T &)); // vist: functionpointer to apply the function to an object stored in a binary
	void inorder(void (*visit)(T &));
	void postorder(void (*visit)(T &));

	int size() const;
	void clear();
	int height() const;

	void print() const; // A method to print out the tree using preorder

	// Big Three: copy constructor, operator=(), destructor
	BinaryTree();
	BinaryTree(const BinaryTree<T> &original);
	BinaryTree<T> &operator=(const BinaryTree<T> &original);
	~BinaryTree();

protected:
	// Auxiliary functions
	void recursive_preorder(BinaryNode<T> *sub_root, void (*visit)(T &));
	void recursive_inorder(BinaryNode<T> *sub_root, void (*visit)(T &));
	void recursive_postorder(BinaryNode<T> *sub_root, void (*visit)(T &));
	int recursive_size(BinaryNode<T> *sub_root) const;
	void recursive_clear(BinaryNode<T> *sub_root);
	int recursive_height(BinaryNode<T> *sub_root) const;
	BinaryNode<Key, T> *recursive_copy(BinaryNode<T> *sub_root);

	void recursive_preorder_print_node(BinaryNode<T> *sub_root) const;

	// Data member
	BinaryNode<T> *root;
};

template <typename T>
BinaryTree<T>::BinaryTree()
/*
Post: An empty binary tree has been created.
*/
{
	root = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &original)
/*
Post: A new binary tree has been created with the same structure and content as those of original.
Uses: The function recursive_copy
*/
{
	root = recursive_copy(original.root);
}

template <typename T>
BinaryTree<T>:: BinaryTree<T> recursive_copy(const BinaryTree<T>* sub_root)
{
	//V-L-R: construct a binary tree
		BinaryNode<T>* parent = new BinaryNode(sub_root->data);
		parent->left = recursive_copy(sub_root->left); //conatruct LST return
		parent->right = recursive_copy(sub_root->right);

	return parent;
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &original)
/*
Post: The binary tree is assigned to copy a parameter
*/
{
	root = recursive_copy(original.root);
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	clear();
}

template <typename T>
bool BinaryTree<T>::empty() const
/*
Post: A result of true is returned if the binary tree is empty.
	  Otherwise, false is returned.
*/
{
}

template <typename T>
void BinaryTree<T>::preorder(void (*visit)(T &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
}

template <typename T>
void BinaryTree<T>::inorder(void (*visit)(T &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
}

template <typename T>
void BinaryTree<T>::postorder(void (*visit)(T &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
	r
}

template <typename T>
int BinaryTree<T>::size() const
/*
Post: The number of entries in the binary tree is returned.
Uses: The function recursive_size
*/
{
	return recursive_size(root);
}

template <typename T>
void BinaryTree<T>::clear()
/*
Post: Dispose of all the nodes of the binary tree.
Uses: The function recursive_clear.
*/
{
	recursive_clear(root);
	root = nullptr;
}

template <typename T>
int BinaryTree<T>::height() const
/*
Post: The height of the binary tree is returned.
Uses: The function recursive_height
*/
{
	return recursive_height(root);
}

template <typename T>
void BinaryTree<T>::print() const
{
	/*
	Post: The tree has been traversed in preorder.  Each node and its two children is printed
	Uses: The function recursive_preorder_print_node
	*/
	cout << endl;
	cout << setw(38) << setfill('+') << " " << endl;
	if (root == nullptr)
		cout << "EMPTY TREE" << endl;
	else
	{
		if (root->left == nullptr && root->right == nullptr)
			cout << setw(12) << setfill(' ') << root->key << ":" << setw(12) << " " << right << setw(14) << " " << endl;

		else
			recursive_preorder_print_node(root);
	}
	cout << setw(38) << setfill('+') << " " << endl;
	cout << setfill(' ') << endl;
}

// Functions

template <typename T>
void BinaryTree<T>::recursive_preorder(BinaryNode<T> *sub_root,
									   void (*visit)(T &))
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder recursively
*/

// V-L-R
// first do omething on the data of the parent, then left child, the
{
	if (sub_root != nullptr)
	{
		visit(sub_root->data);
		recursive_preorder(sub_root->left, visit);
		recursive_preorder(sub_root->right, visit);
	}
}

template <typename T>
void BinaryTree<T>::recursive_inorder(BinaryNode<T> *sub_root,
									  void (*visit)(T &))
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in inorder sequence.
Uses: The function recursive_inorder recursively
*/
{
}

template <typename T>
void BinaryTree<T>::recursive_postorder(BinaryNode<T> *sub_root,
										void (*visit)(T &))
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in postorder sequence.
Uses: The function recursive_postorder recursively
*/
{
}

template <typename T>
int BinaryTree<T>::recursive_size(BinaryNode<T> *sub_root) const
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The number of entries in the subtree is returned.
Uses: The function recursive_size recursively
*/
{
	
}

template <typename T>
void BinaryTree<T>::recursive_clear(BinaryNode<T> *sub_root)
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: All the nodes in the subtree are disposed of in postorder.
Uses: The function recursive_clear recursively
*/
{

}

template <typename T>
int BinaryTree<T>::recursive_height(BinaryNode<T> *sub_root) const
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: the height of the subtree is returned.
Uses: The function recursive_height recursively
*/
{
}
}

template <typename T>
BinaryNode<Key, T> *BinaryTree<T>::recursive_copy(BinaryNode<T> *sub_root)
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: returns a pointer to the root of a new binary tree that has exactly the same structure and content as those of the subtree.
Uses: The function recursive_copy recursively
*/
{
}

template <typename T>
void BinaryTree<T>::recursive_preorder_print_node(BinaryNode<T> *sub_root) const
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder_print_node recursively
*/
{
	if (sub_root != nullptr)
	{
		if (sub_root->left != nullptr || sub_root->right != nullptr)
		{
			cout << setw(12) << setfill(' ') << sub_root->key << ":";
			if (sub_root->left != nullptr)
				cout << setw(12) << setfill(' ') << sub_root->left->key;
			else
				cout << setw(12) << " "; // "-" represents no child
			if (sub_root->right != nullptr)
				cout << setw(12) << setfill(' ') << sub_root->right->key;
			else
				cout << setw(12) << " "; // "-" represents no child
			// cout << "; ";
			cout << endl;
		}
		recursive_preorder_print_node(sub_root->left);
		recursive_preorder_print_node(sub_root->right);
	}
}

#endif
