#pragma once
// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {} //inline function
    // Whenever main calls the Node() function, it will not just call Node() but the whole inline function?s
};

// int main()
// {
//     Node* p1 = new Node(10); // 
// }

