#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <iomanip>
#include "BinaryNode.h"

using namespace std;

template <typename Key, typename Object >
class BinaryTree {
public:
   BinaryTree();
   bool empty() const;
   void preorder(void (*visit)(Object&)); //vist: functionpointer to apply the function to an object stored in a binary
   void inorder(void (*visit)(Object&));
   void postorder(void (*visit)(Object&));

   int size() const;
   void clear();
   int height() const;

   void print() const; // A method to print out the tree using preorder

   //Big Three: copy constructor, operator=(), destructor
   BinaryTree(const BinaryTree<Key, Object> &original);
   BinaryTree<Key, Object>& operator =(const BinaryTree<Key, Object> &original);
   ~BinaryTree();
protected:
   // Auxiliary functions
   void recursive_preorder(BinaryNode<Key, Object> *sub_root, void (*visit)(Object &));
   void recursive_inorder(BinaryNode<Key, Object> *sub_root, void (*visit)(Object &));
   void recursive_postorder(BinaryNode<Key, Object> *sub_root, void (*visit)(Object &));
   int recursive_size(BinaryNode<Key, Object> *sub_root) const;
   void recursive_clear(BinaryNode<Key, Object> *sub_root);
   int recursive_height(BinaryNode<Key, Object> *sub_root) const;
   BinaryNode<Key, Object>* recursive_copy(BinaryNode<Key, Object> *sub_root);

   void recursive_preorder_print_node(BinaryNode<Key, Object> *sub_root) const;

   // Data member
   BinaryNode<Key, Object>* root;
};

template <typename Key, typename Object>
BinaryTree<Key, Object>::BinaryTree()
/*
Post: An empty binary tree has been created.
*/
{
   root = nullptr;
}

template <typename Key, typename Object>
BinaryTree<Key, Object>::BinaryTree(const BinaryTree<Key, Object> &original) 
/*
Post: A new binary tree has been created with the same structure and content as those of original. 
Uses: The function recursive_copy 
*/
{
  root = recursive_copy(original.root);
}

template <typename Key, typename Object>
BinaryTree<Key, Object>& BinaryTree<Key, Object>::operator=(const BinaryTree<Key, Object> &original) 
/*  
Post: The binary tree is assigned to copy a parameter 
*/
{


}

template <typename Key, typename Object>
BinaryTree<Key, Object>::~BinaryTree() {
   clear();
}

template <typename Key, typename Object>
bool BinaryTree<Key, Object>::empty() const
/*
Post: A result of true is returned if the binary tree is empty.
      Otherwise, false is returned.
*/
{
   
}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::preorder(void (*visit)(Object &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
  
}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::inorder(void (*visit)(Object &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   
}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::postorder(void (*visit)(Object &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   r
}

template <typename Key, typename Object>
int BinaryTree<Key, Object>::size() const
/* 
Post: The number of entries in the binary tree is returned.
Uses: The function recursive_size
*/
{
   return recursive_size(root);
}


template <typename Key, typename Object>
void BinaryTree<Key, Object>::clear()
/* 
Post: Dispose of all the nodes of the binary tree.
Uses: The function recursive_clear.
*/
{
   recursive_clear(root);
   root = nullptr;
}

template <typename Key, typename Object>
int BinaryTree<Key, Object>::height() const
/* 
Post: The height of the binary tree is returned.
Uses: The function recursive_height
*/
{
   return recursive_height(root);
}


template <typename Key, typename Object>
void BinaryTree<Key, Object>::print() const{
/* 
Post: The tree has been traversed in preorder.  Each node and its two children is printed 
Uses: The function recursive_preorder_print_node
*/
   cout << endl;
   cout << setw(38) << setfill('+') << " " << endl;
   if(root == nullptr)
      cout << "EMPTY TREE" << endl;
   else{
      if(root->left == nullptr && root->right == nullptr)
         cout << setw(12) << setfill(' ') << root->key << ":" << setw(12) << " " << right << setw(14) << " " << endl;

	  else recursive_preorder_print_node(root);
   }
   cout << setw(38) << setfill('+') << " " << endl;
   cout << setfill(' ') << endl;
}

// Functions

template <typename Key, typename Object>
void BinaryTree<Key, Object>::recursive_preorder(BinaryNode<Key, Object> *sub_root,
                                            void (*visit)(Object &))
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder recursively
*/
{

}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::recursive_inorder(BinaryNode<Key, Object> *sub_root,
                                           void (*visit)(Object &))
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in inorder sequence.
Uses: The function recursive_inorder recursively
*/
{

}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::recursive_postorder(BinaryNode<Key, Object> *sub_root,
                                             void (*visit)(Object &))
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in postorder sequence.
Uses: The function recursive_postorder recursively
*/
{

}

template <typename Key, typename Object>
int BinaryTree<Key, Object>::recursive_size(BinaryNode<Key, Object> *sub_root) const
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The number of entries in the subtree is returned.
Uses: The function recursive_size recursively
*/
{
;
}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::recursive_clear(BinaryNode<Key, Object> *sub_root)
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: All the nodes in the subtree are disposed of in postorder.
Uses: The function recursive_clear recursively
*/
{

}

template <typename Key, typename Object>
int BinaryTree<Key, Object>::recursive_height(BinaryNode<Key, Object> *sub_root) const 
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: the height of the subtree is returned.
Uses: The function recursive_height recursively
*/
{

   }
}   

template <typename Key, typename Object>
BinaryNode<Key, Object>* BinaryTree<Key, Object>::recursive_copy(BinaryNode<Key, Object>* sub_root) 
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: returns a pointer to the root of a new binary tree that has exactly the same structure and content as those of the subtree.
Uses: The function recursive_copy recursively
*/
{

}


template <typename Key, typename Object>
void BinaryTree<Key, Object>::recursive_preorder_print_node(BinaryNode<Key, Object> *sub_root) const
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder_print_node recursively
*/
{
   if (sub_root != nullptr) {
      if(sub_root->left != nullptr || sub_root->right != nullptr){
         cout << setw(12) << setfill(' ') << sub_root->key << ":";
         if(sub_root->left != nullptr)
            cout << setw(12) << setfill(' ') << sub_root->left->key;
         else
            cout << setw(12) << " "; // "-" represents no child
         if(sub_root->right != nullptr)
            cout << setw(12) << setfill(' ') << sub_root->right->key;
         else
            cout << setw(12) << " "; // "-" represents no child
         //cout << "; ";
         cout << endl;
      }
      recursive_preorder_print_node(sub_root->left);
      recursive_preorder_print_node(sub_root->right);
   }
}

#endif
