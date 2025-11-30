#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <iomanip>
#include "BinaryNode.h"

using namespace std;

template <typename Key, typename Object>
class BinaryTree
{
public:
    BinaryTree();
    bool empty() const;
    void preorder(void (*visit)(Object &));
    void inorder(void (*visit)(Object &));
    void postorder(void (*visit)(Object &));

    int size() const;
    void clear();
    int height() const;

    void print() const; // A method to print out the tree using preorder

    // functions added
    void insert(const Key &key, const Object &obj);

	

	// Big Three: copy constructor, operator=(), destructor
    BinaryTree(const BinaryTree<Key, Object> &original);
    BinaryTree<Key, Object> &operator=(const BinaryTree<Key, Object> &original);
    ~BinaryTree();

protected:
    // Auxiliary functions
    void recursive_preorder(BinaryNode<Key, Object> *sub_root, void (*visit)(Object &));
    void recursive_inorder(BinaryNode<Key, Object> *sub_root, void (*visit)(Object &));
    void recursive_postorder(BinaryNode<Key, Object> *sub_root, void (*visit)(Object &));
    int recursive_size(BinaryNode<Key, Object> *sub_root) const;
    void recursive_clear(BinaryNode<Key, Object> *sub_root);
    int recursive_height(BinaryNode<Key, Object> *sub_root) const;
    BinaryNode<Key, Object> *recursive_copy(BinaryNode<Key, Object> *sub_root);

    void recursive_preorder_print_node(BinaryNode<Key, Object> *sub_root) const;

    // Functions added
    BinaryNode<Key, Object> *insert(BinaryNode<Key, Object> *r, const Key key, const Object &obj);

    // Data member
    BinaryNode<Key, Object> *root;
};

// Constructor
template <typename Key, typename Object>
BinaryTree<Key, Object>::BinaryTree() : root(nullptr) {}

// Copy constructor
template <typename Key, typename Object>
BinaryTree<Key, Object>::BinaryTree(const BinaryTree<Key, Object> &original)
{
    root = recursive_copy(original.root);
}

// Assignment operator
template <typename Key, typename Object>
BinaryTree<Key, Object> &BinaryTree<Key, Object>::operator=(const BinaryTree<Key, Object> &original)
{
    if (this != &original)
    {
        clear();
        root = recursive_copy(original.root);
    }
    return *this;
}

// Destructor
template <typename Key, typename Object>
BinaryTree<Key, Object>::~BinaryTree()
{
    clear();
}

// Empty check
template <typename Key, typename Object>
bool BinaryTree<Key, Object>::empty() const
{
    return root == nullptr;
}

// Traversals
template <typename Key, typename Object>
void BinaryTree<Key, Object>::preorder(void (*visit)(Object &))
{
    recursive_preorder(root, visit);
}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::inorder(void (*visit)(Object &))
{
    recursive_inorder(root, visit);
}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::postorder(void (*visit)(Object &))
{
    recursive_postorder(root, visit);
}

// Size
template <typename Key, typename Object>
int BinaryTree<Key, Object>::size() const
{
    return recursive_size(root);
}

// Clear
template <typename Key, typename Object>
void BinaryTree<Key, Object>::clear()
{
    recursive_clear(root);
    root = nullptr;
}

// Height
template <typename Key, typename Object>
int BinaryTree<Key, Object>::height() const
{
    return recursive_height(root);
}

// Print
template <typename Key, typename Object>
void BinaryTree<Key, Object>::print() const
{
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

// Recursive functions
template <typename Key, typename Object>
void BinaryTree<Key, Object>::recursive_preorder(BinaryNode<Key, Object> *sub_root, void (*visit)(Object &))
{
    if (sub_root != nullptr)
    {
        visit(sub_root->object);
        recursive_preorder(sub_root->left, visit);
        recursive_preorder(sub_root->right, visit);
    }
}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::recursive_inorder(BinaryNode<Key, Object> *sub_root, void (*visit)(Object &))
{
    if (sub_root != nullptr)
    {
        recursive_inorder(sub_root->left, visit);
        visit(sub_root->object);
        recursive_inorder(sub_root->right, visit);
    }
}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::recursive_postorder(BinaryNode<Key, Object> *sub_root, void (*visit)(Object &))
{
    if (sub_root != nullptr)
    {
        recursive_postorder(sub_root->left, visit);
        recursive_postorder(sub_root->right, visit);
        visit(sub_root->object);
    }
}

template <typename Key, typename Object>
int BinaryTree<Key, Object>::recursive_size(BinaryNode<Key, Object> *sub_root) const
{
    if (sub_root == nullptr) return 0;
    return 1 + recursive_size(sub_root->left) + recursive_size(sub_root->right);
}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::recursive_clear(BinaryNode<Key, Object> *sub_root)
{
    if (sub_root != nullptr)
    {
        recursive_clear(sub_root->left);
        recursive_clear(sub_root->right);
        delete sub_root;
    }
}

template <typename Key, typename Object>
int BinaryTree<Key, Object>::recursive_height(BinaryNode<Key, Object> *sub_root) const
{
    if (sub_root == nullptr) return 0;
    int leftHeight = recursive_height(sub_root->left);
    int rightHeight = recursive_height(sub_root->right);
    return 1 + max(leftHeight, rightHeight);
}

template <typename Key, typename Object>
BinaryNode<Key, Object> *BinaryTree<Key, Object>::recursive_copy(BinaryNode<Key, Object> *sub_root)
{
    if (sub_root == nullptr) return nullptr;
    BinaryNode<Key, Object> *newNode = new BinaryNode<Key, Object>(sub_root->key, sub_root->object);
    newNode->left = recursive_copy(sub_root->left);
    newNode->right = recursive_copy(sub_root->right);
    return newNode;
}

template <typename Key, typename Object>
void BinaryTree<Key, Object>::recursive_preorder_print_node(BinaryNode<Key, Object> *sub_root) const
{
    if (sub_root != nullptr)
    {
        if (sub_root->left != nullptr || sub_root->right != nullptr)
        {
            cout << setw(12) << setfill(' ') << sub_root->key << ":";
            if (sub_root->left != nullptr)
                cout << setw(12) << setfill(' ') << sub_root->left->key;
            else
                cout << setw(12) << " ";
            if (sub_root->right != nullptr)
                cout << setw(12) << setfill(' ') << sub_root->right->key;
            else
                cout << setw(12) << " ";
            cout << endl;
        }
        recursive_preorder_print_node(sub_root->left);
        recursive_preorder_print_node(sub_root->right);
    }
}

// Insert
template <typename Key, typename Object>
void BinaryTree<Key, Object>::insert(const Key &key, const Object &obj)
{
    root = insert(root, key, obj);
}

template <typename Key, typename Object>
BinaryNode<Key, Object> *BinaryTree<Key, Object>::insert(BinaryNode<Key, Object> *r, const Key key, const Object &obj)
{
    if (r == nullptr)
    {
        r = new BinaryNode<Key, Object>(key, obj);
    }
    else if (key < r->key)
    {
        r->left = insert(r->left, key, obj);
    }
    else if (key > r->key)
    {
        r->right = insert(r->right, key, obj);
    }
    return r;
}

#endif
