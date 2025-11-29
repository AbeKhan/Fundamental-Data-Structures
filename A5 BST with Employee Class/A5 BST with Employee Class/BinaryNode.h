#ifndef BINARY_NODE_H
#define BINARY_NODE_H

template <typename Key, typename Object>
struct BinaryNode
{
   //    data members:
   Key key;
   Object obj;
   BinaryNode<Key, Object> *left;
   BinaryNode<Key, Object> *right;
   //    constructors:
   BinaryNode();
   BinaryNode(const Key &key, const Object &obj);
   Object getData();
   void setData(const Object &);
};

template <typename Key, typename Object>
BinaryNode<Key, Object>::BinaryNode()
{
   left = nullptr;
   right = nullptr;
}

template <typename Key, typename Object>
BinaryNode<Key, Object>::BinaryNode(const Key &key, const Object &obj)
{
   this->key = key;
   this->obj = obj; // may need assignment operator overloading
   left = nullptr;
   right = nullptr;
}

template <typename Key, typename Object>
Object BinaryNode<Key, Object>::getData()
{
   return obj;
}

template <typename Key, typename Object>
void BinaryNode<Key, Object>::setData(const Object &newObj)
{
   this->obj = newObj;
}
#endif
