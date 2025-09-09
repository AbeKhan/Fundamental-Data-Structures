#include <cstddef>

struct node
{
    int data;
    node *next;
};

main()
{
    // these are all pointers, meaning they will hold an address
    node *n; // Will be used to create new nodes (n=new node;)
    node *t; // Will be used to link nodes (t->next=n)
    node *h; // Will hold the head of the node, i.e. the first node, used as a reference to access other nodes.

    // creating the first node
    n = new node; // n is a pointer and now holds the address of a newly created node
    n->data = 1;  // accessing n's data member and setting it equal to 1
    t = n;        // t is now pointing to the newly created node, will be used to link nodes
    h = n;        // h is now pointing to the newly created node and will remain so as a reference

    // creating the second node
    n = new node; // creating the second node
    n->data = 2;  // the new node's member "data" is now equal 2
    t->next = n;  // t is pointing to the previous node, and we'll set it's (previous node's) "next" member which is a pointer of type "node"  to point to the newly created node
    // just like the data type "int" or "double", now our node is a data type
    t = t->next; // t will now point to whatever t's member "next" is pointing to, which is the new node (same thing as t=n, t points to n)
    // thus advancing t (to point to the newly created node)

    // one more node to recap
    n = new node;   // creating a new node
    n->data = 3;    // setting it's member int data = 3
    t->next = n;    // linking the nodes
    t = t->next;    // advancing t
    n->next = NULL; // the new node's next pointer now points to nothing, and we know it's the end of the linked list (same thing as t-<next=NULL), since t is now pointing to n as well
}