#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Node {
private:
    double data;
    Node* next;

public:
    Node(double d) : data(d), next(nullptr) { }
    virtual ~Node() { }

    friend class Stack;
};

class Stack {
private:
    Node* topPtr;

public:
    class StackEmptyException { }; //empty inner class fpr exception handling

    Stack() : topPtr(nullptr) { }

    // Deep copy constructor
    Stack(const Stack& copy) : topPtr(nullptr) {
        if (copy.topPtr == nullptr)
            return;

        // Copy linked list from top to bottom
        Node* current = copy.topPtr;
        Node* newTop = new Node(current->data);
        topPtr = newTop;

        current = current->next;
        while (current != nullptr) {
            newTop->next = new Node(current->data);
            newTop = newTop->next;
            current = current->next;
        }
    }

    // Destructor
    virtual ~Stack() {
        while (topPtr != nullptr) {
            Node* temp = topPtr;
            topPtr = topPtr->next;
            delete temp;
        }
    }

    void push(double value) {
        Node* newNode = new Node(value);
        newNode->next = topPtr;
        topPtr = newNode;
    }

    void pop() {
        if (isEmpty()) {
            throw StackEmptyException();
        }
        Node* oldTop = topPtr;
        topPtr = topPtr->next;
        delete oldTop;
    }

    double top() {
        if (isEmpty()) {
            throw StackEmptyException();
        }
        return topPtr->data;
    }

    bool isEmpty() {
        return topPtr == nullptr;
    }

    bool isFull() {
        // A linked-list stack is full only when memory is exhausted.
        return false;
    }
};

int main() {
    try {
        Stack s;

        cout << "Pushing: 10, 20, 30\n";
        s.push(10);
        s.push(20);
        s.push(30);

        cout << "Current top: " << s.top() << endl;  // 30

        cout << "Popping...\n";
        s.pop();  

        cout << "New top: " << s.top() << endl;      // 20

        cout << "Copying stack...\n";
        Stack s2 = s;     // invoke copy constructor

        cout << "Top of copied stack: " << s2.top() << endl;  // 20

        cout << "Popping original stack...\n";
        s.pop();          // s top becomes 10

        cout << "Top of original: " << s.top() << endl;  // 10
        cout << "Top of copied  : " << s2.top() << endl; // 20 (deep copy)

        cout << "Emptying stack...\n";
        s.pop();
        cout << "Stack empty? " << boolalpha << s.isEmpty() << endl;

        cout << "Trying to pop empty stack...\n";
        s.pop();     // will throw exception

    } catch (Stack::StackEmptyException&) {
        cout << "** Exception: Stack is empty! **\n";
    }

    return 0;
}